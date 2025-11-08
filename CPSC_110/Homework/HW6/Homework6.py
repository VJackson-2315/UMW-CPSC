#4
def anagram(message):
    
    ana = ""
    for letter in message.split():
        letter = letter.upper()
        ana += letter[0]
    return ana

#7
def cipher(key, message):
    key = int(key)
    message = str(message)
    
    newMessage = ""
    for char in message:
        newMessage += chr(ord(char) + key)
    return newMessage

#8
def cipherUpdate(key, message):
    key = int(key)
    message = list(message)
    bank = "abcdefghijklmnopqrstuvwxyz"
    
    newMessage = ""
    for char in message:
        newChar = bank.index(char) + 1
        char = chr(ord(char) + key)
        
        if char not in bank:
            char = ord(char)
            char -= newChar
            char = chr(char)            
        
        newMessage += char           
    
    return newMessage

#9
def wordCount(message):
    message = message.split()
    print("Number of words:", len(message))

#10
def average(message):
    message = message.split()
        
    ave = 0
    for word in message:
        ave += len(word)
        
    ave /= len(message)
    print("Average word length:", ave)