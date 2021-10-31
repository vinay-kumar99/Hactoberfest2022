#include <iostream>
#include <cmath>
using namespace std;


void reverse(int arr[], int low, int high)
{
	while(low < high)
	{
		swap(arr[high], arr[low]);

		low++;
		high--;
	}
}   

void leftRotate(int arr[], int d, int n)
{
	reverse(arr, 0, d - 1);

	reverse(arr, d, n - 1);

	reverse(arr, 0, n - 1);
}
