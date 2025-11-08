# happy.py
def happy():
    print("Happy Birthday to you!")

def sing(person):
    happy()
    happy()
    print("Happy birthday, dear", person + ".")
    happy()

def happy_main():
    sing("Fred")
    print()
    sing("Lucy")
    print()
    sing("Elmer")
    
# futval_3.py
from graphics import *

def drawBar(window, year, height):
    # Draw a bar in window starting at year with given height
    bar = Rectangle(Point(year, 0), Point(year+1, height))
    bar.setFill('green')
    bar.setWidth(2)
    bar.draw(window)
    
def futval3_main():
    # Introduction
    print("This program plots the growth of a 10-year investment.")
    
    # Get principal and interest rate
    principal = float(input("Enter the initial principal: "))
    apr = float(input("Enter the annualized interest rate: "))
    
    # Create a graphics window wtih labels on left edge
    win = GraphWin("Investment Growth Chart", 320, 240)
    win.setBackground("white")
    win.setCoords(-1.75, -200, 11.5, 10400)
    Text(Point(-1, 0), ' 0.0K').draw(win)
    Text(Point(-1, 2500), ' 2.5K').draw(win)
    Text(Point(-1, 5000), ' 5.0K').draw(win)
    Text(Point(-1, 7500), ' 7.5K').draw(win)
    Text(Point(-1, 10000), ' 10.0K').draw(win)
    
    drawBar(win, 0, principal)
    for year in range(1, 11):
        principal *= (1 + apr)
        drawBar(win, year, principal)
        
    input("Press <Enter> to quit")
    win.close
    
# Triangle2.py
import math
from graphics import *

def square(x):
    return x ** 2

def distance(p1, p2):
    dist = math.sqrt(square(p2.getX() - p1.getX())
                     + square(p2.getY() - p1.getY()))
    return dist

def triangle_main():
    win = GraphWin("Draw a Triangle")
    win.setCoords(0.0, 0.0, 10.0, 10.0)
    message = Text(Point(5, 0.5), "Click on three points")
    message.draw(win)
    
    # Get and draw three verticies of triangle
    p1 = win.getMouse()
    p1.draw(win)
    p2 = win.getMouse()
    p2.draw(win)
    p3 = win.getMouse()
    p3.draw(win)
    
    # Use Polygon object to draw the triangle
    triangle = Polygon(p1, p2, p3)
    triangle.setFill("peachpuff")
    triangle.setOutline("cyan")
    triangle.draw(win)
    
    # Calculate the perimeter of the triangle
    perim = distance(p1, p2) + distance(p2, p3) + distance(p3, p1)
    message.setText("The perimeter is: {0:0.2f}".format(perim))
    
    # Wait for another click to exit
    win.getMouse()
    win.close()

# happy2.py
def happy2():
    return "Happy Birthday to you!\n"

def verseFor(person):
    lyrics = happy2()*2 + "Happy birthday, dear " + person + ".\n" + happy2()
    return lyrics

def happy2_main():
    outf = open("Happy_Birthday.txt", "w")
    for person in ["Fred", "Lucy", "Elmer"]:
        print(verseFor(person), file=outf)
    outf.close()
    
# addinterest.py
def addInterest(balance, rate):
    newBalance = balance * (1+rate)
    return newBalance

def interest_test():
    amount = 1000
    rate = 0.05
    amount = addInterest(amount, rate)
    print(amount)
    
# futval_4.py
from graphics import *

def createLabeledWindow():
    window = GraphWin("Investment Growth Chart", 320, 240)
    window.setBackground("white")
    window.setCoords(-1.75, -200, 11.5, 10400)
    Text(Point(-1, 0), ' 0.0K').draw(window)
    Text(Point(-1, 2500), ' 2.5K').draw(window)
    Text(Point(-1, 5000), ' 5.0K').draw(window)
    Text(Point(-1, 7500), ' 7.5K').draw(window)
    Text(Point(-1, 10000), ' 10.0K').draw(window)
    return window

def drawBar2(window, year, height):
    bar = Rectangle(Point(year, 0), Point(year+1, height))
    bar.setFill('green')
    bar.setWidth(2)
    bar.draw(window)
    
def futval4_main():
    print("This program plots the growth of a 10-year investment.")
    
    principal = float(input("Enter the initial principal: "))
    apr = float(input("Enter the annualized interest rate: "))
    
    win = createLabeledWindow()
    drawBar2(win, 0, principal)
    for year in range(1, 11):
        principal *= (1 + apr)
        drawBar2(win, year, principal)
        
    input("Press <Enter> to quit")
    win.close