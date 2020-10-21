// C++ program to implement binary search in sorted array
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
	if (high < low)
		return -1;
	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
		return mid;
	if (key > arr[mid])
		return binarySearch(arr, (mid + 1), high, key);
	return binarySearch(arr, low, (mid - 1), key);
}

/* Driver code */
int main()
{
	// Let us search 3 in below array
	int arr[] = { 5, 6, 7, 8, 9, 10 };
	int n, key;

	n = sizeof(arr) / sizeof(arr[0]);
	key = 10;

	cout << "Index: " << binarySearch(arr, 0, n - 1, key)
		<< endl;
	return 0;
}

// This code is contributed by NamrataSrivastava1
