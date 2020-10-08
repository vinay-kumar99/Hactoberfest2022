#guess game
import random
print('What is your name?')
name=input()
print('Hi '+name+' make a guess of a number between 1 and 15')
secret_number=random.randint(1,16)
chances=0
for chances in range(0,6):
    number=int(input())
    if number==secret_number:
        print('Your guess is correct')
        chances=chances+1
        break
    elif number>secret_number:
        print('Your guess is too high')
        chances=chances+1
    else:
        print('Your guess is too low')
        chances=chances+1
if number!=secret_number:
    print('You took too long to guess')
    print('the correct guess is '+str(secret_number))
else:
    print('You took '+str(chances)+' chances to get the correct guess')
