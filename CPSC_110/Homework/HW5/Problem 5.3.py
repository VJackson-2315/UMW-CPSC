def average():
    total = 0
    count = int(input("How many numbers do you want to average? "))
    
    for i in range(count):
        num = float(input("Enter a number: "))
        total += num
        
    ave = total / count
    print("Average is ", ave)