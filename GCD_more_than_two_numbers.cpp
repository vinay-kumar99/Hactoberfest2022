#include <bits/stdc++.h> 
using namespace std; 

 
int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 

int findGCD(int arr[], int n) 
{ 
	int result = arr[0]; 
	for (int i = 1; i < n; i++) 
		result = gcd(arr[i], result); 

	return result; 
} 


int main() 
{ 
	int arr[] = { 4,24,100,200,8,16}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findGCD(arr, n) << endl; 
	return 0; 
} 
