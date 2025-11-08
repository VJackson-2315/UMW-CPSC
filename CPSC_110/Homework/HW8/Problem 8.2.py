from graphics import *

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