from graphics import *

#1
def main_a():
    win = GraphWin()
    shape = Rectangle(Point(50, 50), Point(25, 25))
    shape.setOutline("red")
    shape.setFill("red")
    shape.draw(win)
    for i in range(10):
        p = win.getMouse()
        c = shape.getCenter()
        dx = p.getX() - c.getX()
        dy = p.getY() - c.getY()
        shape.move(dx, dy)
    win.close()

def main_b():
    win = GraphWin()
    shape = Rectangle(Point(50, 50), Point(25, 25))
    shape.setOutline("red")
    shape.setFill("red")
    shape.draw(win)
    for i in range(10):
        i = shape.clone()
        i.draw(win)
        p = win.getMouse()
        c = shape.getCenter()
        dx = p.getX() - c.getX()
        dy = p.getY() - c.getY()
        i.move(dx, dy)
    win.close()

def main_c():
    win = GraphWin()
    shape = Rectangle(Point(50, 50), Point(25, 25))
    shape.setOutline("red")
    shape.setFill("red")
    shape.draw(win)
    label = Text(Point(100, 100), "Click again to quit")
    for i in range(10):
        i = shape.clone()
        i.draw(win)
        p = win.getMouse()
        c = shape.getCenter()
        dx = p.getX() - c.getX()
        dy = p.getY() - c.getY()
        i.move(dx, dy)
    label.draw(win)
    p = win.getMouse()
    win.close()