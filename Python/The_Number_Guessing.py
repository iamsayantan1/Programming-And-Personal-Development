import random
from The_Number_Guessing_art import logo

print(logo)

print("Welcome to the Number Guessing Game!")
print("I am Thinking of a number between 1 and 100.")

answer = random.randint(0,100)+1
print(f"Pssst, the correct answer is {answer}")

level = input("Choose a difficulty. Type 'easy' or 'hard': ")
if level == 'easy':
    attempts = 10
else:
    attempts = 5

while attempts != 0:
    print(f"You have {attempts} attempts remaining to guess the number.")
    guess = int(input("Make a guess: "))
    attempts = attempts - 1
    if answer == guess:
        print(f"You got it! The answer was {answer}.")
        break
    elif answer > guess:
        print("Too low.")
    else:
        print("Too high.")
    print("Guess again.")

if attempts == 0:
    print("You've run out of guesses, you lose.")