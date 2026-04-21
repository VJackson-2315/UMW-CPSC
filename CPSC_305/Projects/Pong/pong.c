#include <stdio.h>
#include <stdlib.h>

/* the width and height of the screen */
#define WIDTH 240
#define HEIGHT 160

/* these identifiers define different bit positions of the display control */
#define MODE4 0x0004
#define BG2 0x0400

/* this bit indicates whether to display the front or the back buffer
 * this allows us to refer to bit 4 of the display_control register */
#define SHOW_BACK 0x10;

/* the screen is simply a pointer into memory at a specific address this
 *  * pointer points to 16-bit colors of which there are 240x160 */
volatile unsigned short* screen = (volatile unsigned short*) 0x6000000;

/* the display control pointer points to the gba graphics register */
volatile unsigned long* display_control = (volatile unsigned long*) 0x4000000;

/* the address of the color palette used in graphics mode 4 */
volatile unsigned short* palette = (volatile unsigned short*) 0x5000000;

/* pointers to the front and back buffers - the front buffer is the start
 * of the screen array and the back buffer is a pointer to the second half */
volatile unsigned short* front_buffer = (volatile unsigned short*) 0x6000000;
volatile unsigned short* back_buffer = (volatile unsigned short*)  0x600A000;

/* the button register holds the bits which indicate whether each button has
 * been pressed - this has got to be volatile as well
 */
volatile unsigned short* buttons = (volatile unsigned short*) 0x04000130;

/* the bit positions indicate each button - the first bit is for A, second for
 * B, and so on, each constant below can be ANDED into the register to get the
 * status of any one button */
#define BUTTON_A (1 << 0)
#define BUTTON_B (1 << 1)
#define BUTTON_SELECT (1 << 2)
#define BUTTON_START (1 << 3)
#define BUTTON_RIGHT (1 << 4)
#define BUTTON_LEFT (1 << 5)
#define BUTTON_UP (1 << 6)
#define BUTTON_DOWN (1 << 7)
#define BUTTON_R (1 << 8)
#define BUTTON_L (1 << 9)

/* the scanline counter is a memory cell which is updated to indicate how
 * much of the screen has been drawn */
volatile unsigned short* scanline_counter = (volatile unsigned short*) 0x4000006;

/* wait for the screen to be fully drawn so we can do something during vblank */
void wait_vblank() {
    /* wait until all 160 lines have been updated */
    while (*scanline_counter < 160) { }
}

/* return a pointer to one of the 32 screen blocks (0-31) */
volatile unsigned short* screen_block(unsigned long block) {
    /* they are each 2K big */
    return (volatile unsigned short*) (screen + (block * 0x800));
}

/* this function checks whether a particular button has been pressed */
unsigned char button_pressed(unsigned short button) {
    /* and the button register with the button constant we want */
    unsigned short pressed = *buttons & button;

    /* if this value is zero, then it's not pressed */
    if (pressed == 0) {
        return 1;
    } else {
        return 0;
    }
}

/* keep track of the next palette index */
int next_palette_index = 0;

/*
 * function which adds a color to the palette and returns the
 * index to it
 */
unsigned char add_color(unsigned char r, unsigned char g, unsigned char b) {
    unsigned short color = b << 10;
    color += g << 5;
    color += r;

    /* add the color to the palette */
    palette[next_palette_index] = color;

    /* increment the index */
    next_palette_index++;

    /* return index of color just added */
    return next_palette_index - 1;
}

/* a colored square */
struct square {
    unsigned short x, y, width, height;
    unsigned char color;
    unsigned int score; // so the score for the players can be kept track
};

/* put a pixel on the screen in mode 4 */
void put_pixel(volatile unsigned short* buffer, int row, int col, unsigned char color) {
    /* find the offset which is the regular offset divided by two */
    unsigned short offset = (row * WIDTH + col) >> 1;

    /* read the existing pixel which is there */
    unsigned short pixel = buffer[offset];

    /* if it's an odd column */
    if (col & 1) {
        /* put it in the left half of the short */
        buffer[offset] = (color << 8) | (pixel & 0x00ff);
    } else {
        /* it's even, put it in the left half */
        buffer[offset] = (pixel & 0xff00) | color;
    }
}

/* draw a square onto the screen */
void draw_square(volatile unsigned short* buffer, struct square* s) {
    short row, col;
    /* for each row of the square */
    for (row = s->y; row < (s->y + s->height); row++) {
        /* loop through each column of the square */
        for (col = s->x; col < (s->x + s->width); col++) {
            /* set the screen location to this color */
            put_pixel(buffer, row, col, s->color);
        }
    }
}

/* clear the screen right around the square */
void update_screen(volatile unsigned short* buffer, unsigned short color, struct square* s) {
    short row, col;
    for (row = s->y - 3; row < (s->y + s->height + 3); row++) {
        for (col = s->x - 3; col < (s->x + s->width + 3); col++) {
            put_pixel(buffer, row, col, color);
        }
    }
}

void update_ball(volatile unsigned short* buffer, unsigned short color, struct square* s, short delta) {
    short row, col;
    for (row = s->y - (delta * 3); row < (s->y + s->height + (delta * 3)); row++) {
        for (col = s->x - (delta * 3); col < (s->x + s->width + (delta * 3)); col++) {
            put_pixel(buffer, row, col, color);
        }
    }
}
/* this function takes a video buffer and returns to you the other one */
volatile unsigned short* flip_buffers(volatile unsigned short* buffer) {
    /* if the back buffer is up, return that */
    if(buffer == front_buffer) {
        /* clear back buffer bit and return back buffer pointer */
        *display_control &= ~SHOW_BACK;
        return back_buffer;
    } else {
        /* set back buffer bit and return front buffer */
        *display_control |= SHOW_BACK;
        return front_buffer;
    }
}

/* handle the buttons which are pressed down */
void handle_buttons(struct square* s) {
    /* move the square with the arrow keys */
    if (button_pressed(BUTTON_DOWN)) {
        s->y += 1;
    }
    if (button_pressed(BUTTON_UP)) {
        s->y -= 1;
    }
}

void handle_opponent(struct square* s, struct square* ball, short* ball_delta) {
    // If ball is below the opponent
    if (ball->y + (ball->height/2) > s->y + 10) {
        s->y += 1;
    } 
    // If ball is above the opponent
    else if (ball->y + (ball->height/2) < s->y + 20) {
        s->y -= 1;
    }
}

// Does not let paddles go out of bounds
void handle_player_boundaries(struct square* p) {
    if (p->y <= 0) {
        p->y = 1;
    }

    if ((p->y + p->height) >= HEIGHT) {
        p->y = HEIGHT - (1+p->height);
    }
}

/* clear the screen to black */
void clear_screen(volatile unsigned short* buffer, unsigned short color) {
    unsigned short row, col;
    /* set each pixel black */
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            put_pixel(buffer, row, col, color);
        }
    }
}

short score_reset(struct square* s, struct square* player, struct square* opponent) {
    if (s->x <= 0) {
        // Opponent scored
        opponent->score += 1;
    } else if (s->x + s->width >= WIDTH) {
        // Player scored
        player->score += 1;
    }

    // Reset scores, a win or lose if one player reaches 5 points
    if (player->score == 5 || opponent->score == 5) {
        player->score = 0;
        opponent->score = 0;
    }

    // Reset ball
    clear_screen(front_buffer, add_color(0, 0, 0));
    clear_screen(back_buffer, add_color(0, 0, 0));
    s->x = WIDTH/2;
    s->y = (HEIGHT/2)-5;
    s->width = 10;
    s->height = 10;

    if (player->score >= opponent->score) {
        return (short) 1;
    } else {
        return (short) -1;
    }
}

void handle_ball(struct square* s, short* x_delta, short* y_delta, short* hit_count, struct square* player, struct square* opponent) {
    s->x += *x_delta;
    s->y += *y_delta;

    if ((s->y <= abs(*x_delta)-1) || (s->y + s->height >= HEIGHT-(abs(*x_delta)-1))) { // Top and bottom collisions
        *y_delta *= -1;
    }

    // Player collisions
    if ((s->x <= player->x + player->width + abs(*x_delta)) && ((s->y >= player->y-1) && (s->y+s->height <= player->y + player->height+1))) { // Player
        *y_delta *= -1;
        *x_delta *= -1;
        *hit_count += 1;
    }

    if ((s->x + s->height >= opponent->x-abs(*x_delta)) && ((s->y >= opponent->y-1) && (s->y + s->height <= opponent->y + opponent->height+1))) { // Opponent
        *y_delta *= -1;
        *x_delta *= -1;
        *hit_count += 1;
    }

    // Speed up the ball
    // This was to prevent an eternal back and forth with the ball going in the same direction.
    if (*hit_count >= 5) {
        *hit_count = 0;
        if (*x_delta > 0) {
            *x_delta += 1;
        }
        if (*x_delta < 0) {
            *x_delta -= 1;
        }
        if (*y_delta > 0) {
            *y_delta += 1;
        }
        if (*y_delta < 0) {
            *y_delta -= 1;
        }
    }

    if (s->x <= 0 || s->x + s->width >= WIDTH) {
        // Stop the ball
        *x_delta = 0;
        *y_delta = 0;
        *hit_count = 0;

        // Move ball in direction of losing player
        if (player->score >= opponent->score) {
            *y_delta = opponent->y/abs(opponent->y);
        } else {
            *y_delta = player->y/abs(player->y);
        }
        *x_delta = score_reset(s, player, opponent);
    }
}

/* the main function */
int main() {
    /* we set the mode to mode 4 with bg2 on */
    *display_control = MODE4 | BG2;

    unsigned char white = add_color(31, 31, 31);

    /* make a ball and players */
    struct square ball = {WIDTH/2, (HEIGHT/2)-5, 10, 10, white};
    struct square opponent = {WIDTH-10,(HEIGHT/2)-15, 10, 30, white};
    struct square player = {10, 10, 10, 30, white};

    // Make the net
    struct square net[9];
    short  net_y = 0;
    for (int i = 0; i < 9; i++) {
        struct square block = {WIDTH/2-3, net_y, 5, 10, white};
        net[i] = block;
        net_y += 20;
    }

    // Score tallies
    struct square pscore[4];
    struct square oscore[4];
    short tally_x = 87;
    for (int i = 0; i < 4; i++) {
        struct square ptally = {tally_x, 2, 2, 8, add_color(0, 31, 0)};
        pscore[i] = ptally;

        struct square otally = {tally_x+39, 2, 2, 8, add_color(31, 0, 0)};
        oscore[i] = otally;
        tally_x += 4;
    }


    /* add black to the palette */
    unsigned char black = add_color(0, 0, 0);

    /* the buffer we start with */
    volatile unsigned short* buffer = front_buffer;

    /* clear whole screen first */
    clear_screen(front_buffer, black);
    clear_screen(back_buffer, black);

    // Ball deltas
    short ball_x = -1;
    short ball_y = -1;
    short hit = 0;

    /* loop forever */
    while (1) {
        /* clear the screen - only the areas around the square! */
        update_ball(buffer, black, &ball, abs(ball_x));
        update_screen(buffer, black, &player);
        update_screen(buffer, black, &opponent);

        /* draw objects */
        draw_square(buffer, &ball);
        draw_square(buffer, &player);
        draw_square(buffer, &opponent);

        // Net
        for (int i = 0; i < 9; i++) {
            draw_square(buffer, &net[i]);
        }

        // Scores
        if (player.score > 0) {
            for (int i = 0; i < player.score; i++) {
                draw_square(buffer, &pscore[i]);
            }
        }
        if (opponent.score > 0) {
            for (int i = 0; i < opponent.score; i++) {
                draw_square(buffer, &oscore[i]);
            }
        }

        /* handle button input */
        handle_ball(&ball, &ball_x, &ball_y, &hit, &player, &opponent);
        handle_buttons(&player);
        handle_opponent(&opponent, &ball, &ball_x);
        handle_player_boundaries(&player);
        handle_player_boundaries(&opponent);

        /* wiat for vblank before switching buffers */
        wait_vblank();

        /* swap the buffers */
        buffer = flip_buffers(buffer);
    }
}

