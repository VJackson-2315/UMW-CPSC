from graphics import *

def negate(file):
    img = Image(Point(0, 0), file)
    width = img.getWidth()
    height = img.getHeight()
    win = GraphWin("Negative", width + 2, height + 2)
    
    img.move(width//2, height//2)
    img.draw(win)
    win.getMouse()
    img.undraw()

    for y in range(height):
        for x in range(width):
            r,g,b = img.getPixel(x, y)
            newR, newG, newB = 255 - r, 255 - g, 255 - b
            img.setPixel(x, y, color_rgb(newR, newG, newB))
    
    img.draw

    win.getMouse()
    win.close()