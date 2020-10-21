//Find the peak element in the given array
//ex - (5,20,4)
// 20 is peak element because 20 is greater or equal to its right and left

#include <iostream>
#include <algorithm>

using namespace std;

int peak(int arr[], int n){
    int l = 0;
    int h = n-1;

    while (l<=h){
        int mid = (l+h)/2;
        if (mid > 0 && mid < h){

            if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid -1]){
                return arr[mid];
            }
            else if (arr[mid] < arr[mid+1]){
                l = mid+1;
            }
            else if(arr[mid] < arr[mid-1]){
                h = mid -1;
            }
        }


        //now checking the edge cases if last or first elemnt is peak
        else if(mid ==0 || mid == n-1){
            if (arr[mid] > arr[mid+1]){
                return arr[mid];
            }
            else if(arr[mid]> arr[mid-1]){
                return arr[mid];
            }
        }
        
    }
    return -1;
}


int main() {
    // int arr[] = {15,5,23,90,67};
    // int arr[] = { 1, 3,  1, 0 }; 
    // int arr[] = {5,10,20,15,7};
    int arr[] = {20,10,4,7};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout << peak(arr, n);
    return 0;
}