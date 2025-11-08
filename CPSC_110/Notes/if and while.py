import random

minimum = 1
maximum = 100

secret_number = random.randint(1, 100)
print("Cheat code:", secret_number)

guess = (minimum + maximum) // 2
number_of_guesses = 1

while guess != secret_number:
    number_of_guesses += 1
    if guess > secret_number:
        maximum = guess
        print("high. New guess is", guess)
        guess = (minimum + maximum) // 2
    if guess < secret_number:
        minimum = guess
        print("low. New guess is", guess)
        guess = (minimum + maximum) // 2

print("Success! Your secret number was", guess)
print("Number of guesses:", number_of_guesses)