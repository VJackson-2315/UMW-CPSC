def up_this(message, letter):    
    message = list(message)
    new_string = ""
    
    for char in message:
        if letter in char:
            char = char.upper()
        
        new_string += char
    
    return new_string