//find the left most element in given sorted array 

#include <iostream>
#include <algorithm>

using namespace std;

int find(int arr[], int l ,int h,int x){
    int mid = l + (h-l)/2;
    
    if (l >= h){
        return -1;
    }

    if (arr[mid] == x && (mid == 0 ||  arr[mid-1] != x)){
        return mid;
    }
    if (arr[mid] >= x){
        return find(arr,l, mid-1,x);
    }
    else{
        return find(arr, mid+1,h,x);
    }


}

int main()
{
    int arr[] = {2,3,3,3};
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    int h = n-1;
    cout << find(arr,l,h,x);
    return 0;
}