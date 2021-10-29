t=list(map(int,input().split()))
x=list(str(t[0]-t[1]))
while int(x[0])==0:
    x.pop(0)
if(int(x[0])==1):
    x[0]=str(int(x[0])+1)
else:
    x[0]=str(int(x[0])-1)
print(*x,sep='')