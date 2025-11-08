from graphics import *

def redact(filename):
    with open(filename) as original:
        with open(filename +'.nocat.txt', 'w') as new:
            redact_count = 0
            for line in original:
                if "cat " in line:
                    new.write("REDACTED \n")
                    redact_count += 1
                else:
                    new.write(line)
                    
            return redact_count
        
def many_rects(color_list):
    win = GraphWin("Color Rectangles")
    quit_box = Rectangle(Point(0, 0), Point(10, 10))   
    quit_box.draw(win)
    click = win.getMouse()
    
    for color in color_list:
        if click.getX() > 10 and click.getY() > 10:
            p1 = Point(click.x, click.y)
            click = win.getMouse()
            p2 = Point(click.x, click.y)
            shape = Rectangle(p1, p2)
            shape.setFill(color)
            shape.draw(win)
            color_list.append(color)           
            click = win.getMouse()
            
        else:       
             win.close()


if __name__ == '__main__':
    print("Canceled", redact('cancel_cat_sample.txt'), "cat lines")
    many_rects(['red', 'blue', 'green', 'yellow', 'orange', 'purple'])