from graphics import *

win = GraphWin("Testing Graphics", 1001, 601)

win.setBackground('red')

p = Point(200, 400)

p1 = Point(450, 40)
p2 = Point(500, 140)
p3 = Point(550, 40)
tri = Polygon(p1, p2, p3)
tri.setFill('blue')

circ = Circle(p, 100)
circ.setFill('yellow')

circ.draw(win)
p.draw(win)
tri.draw(win)

win.getMouse()

win.close()