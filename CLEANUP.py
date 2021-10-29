t=int(input())
while(t!=0):
    n,m=map(int,input().split())
    N=list(range(1,n+1))
    M=list(map(int,input().split()))
    [N.remove(x) for x in M]
    N.sort()
    chef=[N[x] for x in range(len(N)) if x%2==0]
    ass=[N[x] for x in range(len(N)) if x%2==1 and x!=0]
    print(*chef, sep=' ')
    print(*ass, sep=' ')
    t=t-1