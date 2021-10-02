year = int(input())
if year%4==0:
    if year%100==0:
        if year%400==0:
            print("leap year")
        else:
            print("Non leap year")
    else:
        print(" leap year")
else:
    print("Non leap year")        
                  
     
