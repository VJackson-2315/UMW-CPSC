import random

minimum = 1
maximum = 100

secret_number = random.randint(1, 100)

guess = 1

print(guess)

while guess != secret_number:
    guess += 1
    print(guess)

print("Success! Your secret number was", guess)
