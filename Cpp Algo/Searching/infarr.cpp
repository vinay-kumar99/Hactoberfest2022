// In a given infinite sorted array you have to find the element x;

#include <iostream>
#include <algorithm>

//ex - arr[] = {1,2,3,4,5,6  .......infinite};
int binaryHelper(int arr[] , int l , int h , int x){
    if (l >= h){
        return -1;
    }
    int mid = (l+h)/2;

    if (arr[mid] == x){
        return mid;
    }
    if (arr[mid] > x ){
        return binaryHelper(arr, l , mid-1,x);

    }else{
        return binaryHelper(arr, mid+1,h, x);
    }

}


int find(int arr[],int x){
    if (arr[0] == x){
        return 0;
    }
    int i = 1;
    while (arr[i] < x){
        i = i * 2;
    }
    if (arr[i] == x){
        return i;
    }
    else {
        return binaryHelper(arr, i/2,i,x);
    }


}



int main() {
    int arr[] = {1,3,5,7,9,11,13,14,15,17};
    int x = 13;
    int res = find(arr,x);
    printf("%d",res);
    return 0;
    
}
