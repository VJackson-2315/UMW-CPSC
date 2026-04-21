#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Score {
    char name[3];
    int score;
};
typedef struct Score Score;

int score_set(Score* hs, char* name, int score) {
    if (strlen(name) > 3 || score < 0) {
        return 0;
    }
    strcpy(hs->name, name);
    hs->score = score;
}

void score_print(Score* hs) {
    printf("%s %d\n", hs->name, hs->score);
}

int score_compare(Score* score1, Score* score2) {
    if (score1->score < score2->score) {
        return 1;
    } else if (score2->score < score1->score) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    /* create an array of scores */
    Score scores[10];

    /* put in some test data */
    score_set(&scores[0], "IAN", 750);
    score_set(&scores[1], "BOB", 1200);
    score_set(&scores[2], "ADA", 3500);
    score_set(&scores[3], "SUE", 900);
    score_set(&scores[4], "EVA", 500);
    score_set(&scores[5], "BEN", 1500);
    score_set(&scores[6], "ROY", 3000);
    score_set(&scores[7], "KIM", 1250);
    score_set(&scores[8], "VIC", 2500);
    score_set(&scores[9], "DAN", 1800);

    /* sort them using the compare function above */
    qsort(scores, 10, sizeof(Score), 
        (int (*) (const void*, const void*)) &score_compare);

    /* display them */
    for (int i = 0; i < 10; i++) {
        score_print(&scores[i]);
    }

    return 0;
}
