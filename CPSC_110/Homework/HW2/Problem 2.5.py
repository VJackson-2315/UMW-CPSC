grade = float(input("What is your grade? "))

if grade >= 90:
    print("You got an A.")
elif 90 > grade >= 80:
    print("You got a B.")
elif 80 > grade >= 70:
    print("You got a C.")
elif 70 > grade >= 60:
    print("You got a D.")
else:
    print("You got an F.")