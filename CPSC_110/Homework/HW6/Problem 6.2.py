def cipher(key, message):
    key = int(key)
    message = str(message)
    
    newMessage = ""
    for char in message:
        newMessage += chr(ord(char) + key)
    return newMessage