#create random unique id of 6 digit
#can be used for creating random id feature for programs

import random
import string

def ran_id():
    return ''.join(random.choice(string.digits) for i in range(6))

if __name__=="__main__":
    l=[]
	#take user input for number of id to be generated
    for i in range(int(input())):
        while True:
            x=ran_id()
            if x not in l:
                l.append(x)
                print(i+1,"ID :",ran_id())
                break
        
