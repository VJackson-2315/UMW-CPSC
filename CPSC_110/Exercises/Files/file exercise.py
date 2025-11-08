fh = open('pi_digits.txt')

text = fh.read()
print(text)

first = fh.readline()
print(first)
second = fh.readline()
print(second)
third = fh.readline()
print(third)

line_list = fh.readlines()
print(line_list)


# first_11_pi = float(fh.readline())
# radius = 1
# cir = 2 * radius * first_11_pi
# print(cir)

pi = 0
for line in fh:
    pi += float(fh.readline())            

fh.close()