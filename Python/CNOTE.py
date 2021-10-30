t=int(input())
while(t):
    x,y,k,n=map(int,input().split())
    count=0
    for i in range(n):
        a,b=map(int,input().split())
        if(count==1):
            continue
        elif(b<=k):
            if(x<=y+a):
                count=1
    if(count==1):
        print("LuckyChef")
    else:
        print("UnluckyChef")
    
    t=t-1