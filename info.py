import sys

def getStats(smin, smax):
    max = int(smax)
    min = int(smin)
    range = max - min
    print('The range is: ' + str(range))
    midpoint = (float(max + min)/2.0)
    print('The midpoint is ' + str(midpoint))

def getLowGuesses(smin, smax):
    max = int(smax)
    min = int(smin)
    midpoint = (max + min) / 2
    guesses = 0
    difference = max - min
    while difference > 2:
        max = midpoint
        midpoint = (max + min) / 2
        difference = max - min
        guesses += 1

    return guesses


def guessingGame(smin, smax):
    max = int(smax)
    min = int(smin)
    correct = False
    guess = 0
    while (not(correct)):
        guess = int((max + min)/2)
        try:
            choice = input('My guess is... ' + str(guess) + '. Is that right, high or low? (c for correct, h for high, l for low): ')
            if (choice.lower() == 'c'):
                correct = True
            elif (choice.lower() == 'h'):
                if (max - min == 1):
                    print("You're lying...it's " + str(guess))
                    break
                max = guess
            elif (choice.lower() == 'l'):
                if (max - min == 1):
                    print("You're lying... it's " + str(guess))
                    break
                min = guess
            else:
                print("That wasn't an option...")
        except TypeError:
            print("Enter H, C or L.")

    print("I told you I could guess it.")


try:
    min = sys.argv[1]
    max = sys.argv[2]
    print('Minimum number: ' + min)
    print('Maximum number: ' + max)
    getStats(min, max)
    print("I bet if you a think of a number between " + min + " and " + max + " I can guess it in under " + str(getLowGuesses(min, max) + 1) + " guesses.")
    input("Do you believe me? : ")
    print("It doesn't matter what you say, I'll prove it.")
    guessingGame(min, max)
    sys.exit()
except IndexError:
    print('not enough arguments passed to system')
    sys.exit()

