import random
# from turtle import clear

words = ["appleshake", "banannashake", "orangeshake", "mangoshake", "pearshake"]
man = ["O", "/", "|", "\\", "/", "\\"]
word = random.choice(words)

# IF False == "_"
dash = []
for _ in range(len(word)):
    dash += "_"

count_lives = count_dash = len(man)

while count_lives != 0 or count_dash != 0:
    flag = False
    count_dash = dash.count("_")
    choice = input("Guess a letter: ").lower()
    # clear()
    for letter in range(len(word)):
        if choice == word[letter]:
            dash[letter] = choice
            flag = True

    if flag == False:
        print("You guessed {choice}, that's not in the word. You lose a life.")
        count_lives -= 1

print("Game Over!")

if count_lives == 0:
    print("You loose.")
else:
    print("You won.")