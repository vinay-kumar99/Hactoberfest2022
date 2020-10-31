#code by codeheist India
def leftRotate(arr, d, n): 
	for i in range(gcd(d,n)): 
		temp = arr[i] 
		j = i 
		while 1: 
			k = j + d 
			if k >= n: 
				k = k - n 
			if k == i: 
				break
			arr[j] = arr[k] 
			j = k 
		arr[j] = temp 
def printArray(arr, size): 
	for i in range(size): 
		print ("%d" % arr[i], end=" ") 

def gcd(a, b): 
	if b == 0: 
		return a; 
	else: 
		return gcd(b, a%b) 
 
arr = [1, 2, 3, 4, 5, 6, 7] 
leftRotate(arr, 2, 7) 
printArray(arr, 7) 
