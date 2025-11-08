def fibo(term):
    start = 0
    next_num = 1    
    count = 1
    
    while count <= term:
        ans = start + next_num
        start = next_num
        next_num = ans
        count += 1
    print("f_", term, " = ", ans, sep = "")