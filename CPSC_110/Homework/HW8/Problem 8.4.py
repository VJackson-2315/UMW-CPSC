from graphics import *

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
    
    p1.draw(win)
    p2.draw(win)
    p3.draw(win)
    tri.draw(win)
    
    win.getMouse()
    win.close()