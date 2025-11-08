from graphics import *
from time import sleep

win = GraphWin("Game", 1001, 601)
light_blue = color_rgb(180, 200, 255)
win.setBackground(light_blue)
win.setCoords(0, 0, 100, 10)

wings = Polygon(Point(35, 0), Point(50, 2), Point(65, 0))
wings.setFill('green')
wings.draw(win)

ship = Polygon(Point(45, 0), Point(50, 4), Point(55, 0))
ship.setFill('red')
ship.draw(win)

speed = 0

while True:
    key = win.checkKey()
    sleep(30)
    if key == 'q':
        break
    elif key == 'Left' or key == 'a':
        speed = -2
    elif key == 'Right' or key == 'd':
        speed = 2
    elif key == 's':
        speed = 0
    wings.move(speed, 0)
    ship.move(speed, 0)

win.getMouse()
win.close()