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

#2
def target():
    win = GraphWin()
    anchor = Point(100, 100)
    
    outer1 = Circle(anchor, 100)
    outer1.setFill('white')
    outer1.setOutline('white')
    outer1.draw(win)
    
    outer2 = Circle(anchor, 80)
    outer2.setFill('black')
    outer2.setOutline('black')
    outer2.draw(win)
    
    outer3 = Circle(anchor, 60)
    outer3.setFill('blue')
    outer3.setOutline('blue')
    outer3.draw(win)
    
    outer4 = Circle(anchor, 40)
    outer4.setFill('red')
    outer4.setOutline('red')
    outer4.draw(win)
    
    center = Circle(anchor, 20)
    center.setFill('yellow')
    center.setOutline('yellow')
    center.draw(win)
    
    win.getMouse()
    win.close()

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
    
#10
def triangle():
    win = GraphWin()
    cursor1 = win.getMouse()
    cursor2 = win.getMouse()
    cursor3 = win.getMouse()
    
    p1 = Point(cursor1.getX(), cursor1.getY())
    p2 = Point(cursor2.getX(), cursor2.getY())
    p3 = Point(cursor3.getX(), cursor3.getY())
    
    tri = Polygon(p1, p2, p3)
    
    tri.draw(win)
    tri.setFill('blue')
    
    win.getMouse()
    win.close()