#1
def checksum(message):  
    sum = 0
    for char in message:
        val = ord(char)
        sum += val
    
    ans = sum % 10
    
    return ans

#2
def up_this(message, letter):    
    message = list(message)
    new_string = ""
    
    for char in message:
        if letter in char:
            char = char.upper()
        
        new_string += char
    
    return new_string

#3
def count_word(file, word):
    wordCount = 0
    with open(file, 'r') as fh:      
        for line in fh:
            if word in line:
                wordCount += 1
        
        return wordCount
        fh.close()
        
def main():
    file = input("What file should I search? ")
    word = input("What word should I count? ")
    
    print(count_word(file, word))

#4
def count_word_no_case(file, word):
    wordList = list(word)
    firstLetter = wordList[0].upper()
    
    newWord = firstLetter
    for char in wordList[1:]:
        newWord += char

    wordCount = 0
    with open(file, 'r') as fh:      
        for line in fh:
            if newWord in line:
                wordCount += 1
        
        print(wordCount)
        fh.close()
