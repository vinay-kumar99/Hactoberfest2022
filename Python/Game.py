#Choices weren't getting checked correctly - So no winner whatsoever as comaparing of string with integer

import random
choice=random.choice(range(21))
print (choice)

def print_pause(msg_to_print):
    print(msg_to_print)
    time.sleep(2)

def intro(choice):
    print("Choose a number within the range of 20\n")

intro(choice)


def try1():
    
    c1=int(input("I guess the number is.. "))
    if choice == c1:
        print("\nCongratulations! Your guess is correct - You Won")
        print ("Your Total score is 100 - Excellent")
        exit()
    else :
        print("\nOops! Incorrect, Try again..")
try1()


def hint1():
    if choice%2 == 0:
        print("Hint: The number is even\n")
    else:
        print("Hint: The number is odd\n")
hint1()

def try2():
    c2=int(input("I guess the number is.. "))
    if choice == c2:
        print("\nCongratulations! Your guess is correct - You Won")
        print("Your Total score is 80 - Very Good")
        exit()
    else :
        print("\nOops! Again Incorrect, Try again..")
try2()

def hint2():
    if 10<choice<21 :
        print("Hint: The number is greater than 10\n")
    elif 0<choice<11 :
        print("Hint: The number is smaller than 10\n")
    else :
        print("The number is not in the given range\n")
hint2()

def try3():
    c3=int(input("I guess the number is.. "))
    if choice == c3:
        print("\nCongratulations! Your guess is correct - You Won")
        print("Your Total score is 60 - Good")
        exit()
    else :
        print("\nUmm - Incorrect, Try again..")
try3()

  
def hint3():
    if choice%3 == 0:
        print("Hint: The number is divisible by 3\n")
    else:
        print("Hint: The number is not divisible by 3\n")
hint3()

def last_try():
    c4=int(input("I guess the number is.. "))
    if choice == c4:
        print("\nCongratulations! Your guess is correct - You Won")
        print("Your Total score is 40 - Average")
        exit()
    else :
        print("\nHard Luck - You Lost, you were unable to guess the correct number in 4 attempts")
last_try()

score=int()

#t_score not working and there's no need to use it

    
print("The correct answer is "+ str(choice))
print("Your total score is 0")

