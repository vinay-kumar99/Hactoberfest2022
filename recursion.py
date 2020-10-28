def factorial(x):
    """This is a recursive function
    to find the factorial of an integer"""

    if x == 1:
        return 1
    else:
        return (x * factorial(x-1))


num = 3
print("The factorial of", num, "is", factorial(num))




def recursive_fibonacci(n): 
   if n <= 1: 
       return n 
   else: 
       return(recursive_fibonacci(n-1) + recursive_fibonacci(n-2)) 
   
n_terms = 10
    
if n_terms <= 0: 
   print("Invalid input ! Please input a positive value") 
else: 
   print("Fibonacci series:") 
   for i in range(n_terms): 
       print(recursive_fibonacci(i))
