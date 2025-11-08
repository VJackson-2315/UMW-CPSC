num = 1
while num <= 100:
    if num % 2 == 0:
        print("Fizz")
        
    if num % 5 == 0:
        print("Buzz")
        
    if num % 7 == 0:
        print("Bang")
    
    else:
        print (num)
    num += 1  
print("Done")