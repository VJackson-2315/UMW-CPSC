def cipherUpdate(key, message):
    key = int(key)
    message = list(message.lower)
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