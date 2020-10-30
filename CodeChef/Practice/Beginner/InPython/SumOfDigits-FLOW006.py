t = int(input())
# how many iterations user wants

lst = []
# list containing initial numbers input
for count in range(t):
    lst.append(input())
lstSum = []
# list containing sum of digits of number
for element in lst:
    sum = 0
    for digit in range(len(element)):
        sum += int(element[digit])
    lstSum.append(sum)
for i in lstSum:
    print(i)
