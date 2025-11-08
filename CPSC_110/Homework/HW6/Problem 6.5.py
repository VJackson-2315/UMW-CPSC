def average(message):
    message = message.split()
    
    ave = 0
    for word in message:
        ave += len(word)
    
    ave /= len(message)
    print("Average word length:", ave)