def checksum(message):  
    sum = 0
    for char in message:
        val = ord(char)
        sum += val
    
    ans = sum % 10
    
    return ans