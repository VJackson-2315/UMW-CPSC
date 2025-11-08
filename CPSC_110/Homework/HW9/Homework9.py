#11
def squareEach(nums):
    newNums = []
    for x in nums:
        newNums.append(x ** 2)
    return newNums

#12
def sumList(nums):
    newSum = 0
    for x in nums:
        newSum += x
    return newSum

#13
def toNumbers(strList):
    newList = []    
    for word in strList:
        wordList = list(word)
        newNum = 0
        for letter in wordList:
            newNum += ord(letter)
        newList.append(newNum)
        
    return newList

#14
def fileRead():
    file = input("What is the name of the file? ")
    with open(file) as in_file:
        for line in in_file:
            line = list(line)
            lineList = toNumbers(line)
        sqrList = squareEach(lineList)
        newList = sumList(sqrList)
        print(newList)

#17
from graphics import *

def moveTo(shape, newCenter): # Function that goes in a program    
    cent = shape.getCenter()
    dx = newCenter.getX() - cent.getX()
    dy = newCenter.getY() - cent.getY()
    shape.move(dx, dy)

def circleClick():
    win = GraphWin()
    circ = Circle(Point(50, 50), 10)
    circ.setFill("blue")
    circ.draw(win)
    for i in range(10):
        p = win.getMouse()
        moveTo(circ, p)
    win.getMouse()
    win.close()

# Test Cases
if __name__ == '__main__':
    print(squareEach([1, 2, 3, 4]))
    print(sumList([1, 2, 3, 4]))
    print(toNumbers(["Hello", "Goodbye"]))
    fileRead()
    circleClick()