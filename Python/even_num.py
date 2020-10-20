 
start = int(input("Enter the start of range: ")) 
end = int(input("Enter the end of range: ")) 
   
for num in range(start, end + 1): 
      
    if num % 2 != 0: 
        print(num, end = " ")
