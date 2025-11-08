#17
from graphics import *
win = GraphWin()

def moveTo(shape, newCenter): # Function that goes in a program    
    cent = shape.getCenter()
    dx = newCenter.getX() - cent.getX()
    dy = newCenter.getY() - cent.getY()
    shape.move(dx, dy)

def circleClick():
    circ = Circle(Point(50, 50), 10)
    circ.setFill("blue")
    circ.draw(win)
    for i in range(10):
        p = win.getMouse()
        moveTo(circ, p)
    win.getMouse()
    win.close()

circleClick()