cp = int(input())
sp = int(input())
profit = sp-cp
Loss = cp-sp
if sp>cp:
    print("Profit is ",profit,"rupees")
else:
    print("Loss is ",Loss,"rupees")