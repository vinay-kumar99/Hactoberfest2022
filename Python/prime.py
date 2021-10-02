# Python program to check if 
# given number is prime or not 
#change done here is that you can input any number and can check if its prime or not
num = int(input('Enter no. : '))
flag=1
# If given number is greater than 1 
if num > 1: 
	
	# Iterate from 2 to n / 2 
	for i in range(2, num//2): 
		
		# If num is divisible by any number between 
		# 2 and n / 2, it is not prime 
		if (num % i) == 0: 
			flag = 0
			break
		else: 
			flag = 1 
			
	if flag==1:
		print(f'{num} is prime')
	else:
		print(f'{num} is not prime')
		
else:
	print('Please enter no. greater than 1')
