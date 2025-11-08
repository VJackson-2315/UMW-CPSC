n = int(input("Enter a number.  "))

count = 1
sqr = count ** 2
total = 0

while count <= n:
    total += sqr
    count += 1
    sqr = count ** 2

print("Sum is", total)