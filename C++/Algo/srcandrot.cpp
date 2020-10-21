//A given sorted array is rotate by distinct elements . find x a number in logn time complexity 

//check if present or not 

//variation of this question 
//find the maximum number in this array which is a pivot
// find the smallest number which is next element than pivot 
//ex- {10,20,40,50,6,7,8}
//pivot - 50 is also maximum
//6 which is next to pivot is smallest



#include <iostream>
#include <algorithm>



int findpivot(int arr[], int n){  

    int l=0;
    int h = n-1;

    if (arr[l] <= arr[h]){
        return 0;

    }
  
    while (l<=h){
      int mid = ( l + h )/ 2;

    if(arr[mid]> arr[mid+1]){
        return mid;
        break;
    }
    if (arr[l] >= arr[mid]){
        h = mid -1;


    }
    else {
        l = mid+1;
    }


    }

    return -1;

}

int main() {
    // int arr[] = {10,20,40,50,7,8,9};
    int arr[] = {10,20,40,50,60,1};
    // int arr[] = {10,20,1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = findpivot(arr, n);
    printf("%d",res);
    return 0;
}

