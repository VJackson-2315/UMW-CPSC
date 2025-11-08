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