from graphics import *

#3
def face():
    win = GraphWin()
    
    head = Circle(Point(100, 100), 75)
    head.setFill("yellow")
    head.draw(win)
    
    left_eye = Circle(Point(65, 75), 10)
    left_eye.setFill("black")
    left_eye.draw(win)
    
    right_eye = left_eye.clone()
    right_eye.draw(win)
    right_eye.move(65, 0)
    
    mouth = Line(Point(50, 125), Point(150, 125))
    mouth.draw(win)
    
    win.getMouse()
    win.close()