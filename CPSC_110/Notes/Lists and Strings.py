grades = input("Enter your grades separated by commas: ")

grades_str_list = grades.split(',')

total = 0
for grades_str in grades_str_list:
    total += float(grades_str)
ave = total / len(grades_str_list)

print(ave)