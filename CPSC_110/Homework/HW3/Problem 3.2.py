m = int(input("Pick a number.  "))
n = int(input("Pick another number.  "))
ans = m + 1

while n < m:
    n = int(input("Too low. Pick another number.  "))

while n >= m:
    fib = int(ans + m)
    print(m, "+", ans, "=", fib)
    ans = fib
    m += 1