#14
def squareEach(nums):
    newNums = []
    for x in nums:
        newNums.append(x ** 2)
    return newNums

def sumList(nums):
    newSum = 0
    for x in nums:
        newSum += x
    return newSum

def toNumbers(strList):
    newList = []    
    for word in strList:
        wordList = list(word)
        newNum = 0
        for letter in wordList:
            newNum += ord(letter)
        newList.append(newNum)
        
    return newList

def fileRead():
    file = input("What is the name of the file? ")
    with open(file) as in_file:
        for line in in_file:
            line = list(line)
            lineList = toNumbers(line)
        sqrList = squareEach(lineList)
        newList = sumList(sqrList)
        print(newList)