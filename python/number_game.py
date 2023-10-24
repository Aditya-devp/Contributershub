import sys
import random

name = input("please enter your name: " + "\n")

fact = input("please write true " + "\n")

while fact != ("true"):
    sys.stdout.write("id recommend you write true " + "\n" + "\n")
    fact = input("please write true  " + "\n"+"\n")

sys.stdout.write("hello " + name + "!"+"\n"+"\n")

message1 = "please be patient"
sys.stdout.write(str(message1)+"\n"+"\n")
message = "thankyou for being patient"
sys.stdout.write(str(message)+"\n"+"\n")

yes = input("are you ready to play a game? " + "\n")
if yes != ("yes"):
    sys.stdout.write("too bad lets start! "+"\n"+"\n")

elif yes == "yes":
    sys.stdout.write("okay! lets go" + "\n"+"\n")

n = random.randint(1, 1000)
sys.stdout.write("im thinking of a random number between 1 & 1000"+"\n")

Guesses = []

gamma = True
while gamma:

    guess_str = input("take a guess ")

    guess = int(guess_str)
    Guesses.append(guess)

    if guess == n:

        sys.stdout.write("well done, thats correct"+"\n")

        sys.stdout.write("you used " + str(len(Guesses)) + " Guesses\n")

        if len(Guesses) < 5:

            sys.stdout.write("you got an A")
        elif len(Guesses) < 10:
            sys.stdout.write("you got a B")
        elif len(Guesses) < 15:
            sys.stdout.write("you got a C")
        elif len(Guesses) < 20:
            sys.stdout.write("you got a D")
        else:
            sys.stdout.write("you got a F")

        gamma = False
    elif guess < n:
        sys.stdout.write("try a bigger number ")
    else:
        sys.stdout.write("try a smaller number ")
