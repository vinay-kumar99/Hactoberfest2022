t = int(input())
# how many iterations user wants

lstA, lstB = [], []
for count in range(t):
    a, b = input().split()
    a, b = int(a), int(b)
    lstA.append(a)
    lstB.append(b)
for count in range(t):
    print(lstA[count] + lstB[count])
