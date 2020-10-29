# Pooja would like to withdraw X $US from an ATM. The cash machine will only accept the transaction if X is a multiple of 5,
# and Pooja's account balance has enough cash to perform the withdrawal transaction (including bank charges).
# For each successful withdrawal the bank charges 0.50 $US. Calculate Pooja's account balance after an attempted transaction.

amountRequested, currentBalance = input().split()
# amount entered by pooja and balance available in account
withdrawAmount = 0
# amount withdrawn after processing transaction
amountRequested = int(amountRequested)
currentBalance = float(currentBalance)

# * requested amount should be multiple of 5 and less than available balance
if currentBalance < 2000 and amountRequested < 2000:
    if amountRequested % 5 == 0 and amountRequested <= currentBalance-0.5:
        withdrawAmount = amountRequested

    currentBalance = currentBalance - amountRequested - 0.5
    print("{0:.2f}".format(currentBalance))
