def anagram(message):
    
    ana = ""
    for letter in message.split():
        letter = letter.upper()
        ana += letter[0]
    return ana