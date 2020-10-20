//Count the number of 1s in given array ;

//ex = {0,0,0,0,1,1,1,1,1}

#include <iostream>
#include <algorithm>

int count(int arr[],int n){
    int low = 0;
    int high = n -1;
    int res = -1;
    while (low <= high){
        int mid = (low + high)/2;

        if (arr[mid]==1){
            res = mid;
            high = mid - 1;

        }
        else{
            low = mid +1;
        }
    }
    return res;
}


int main() {

    int arr[] = {0,0,0,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int leftidx = count(arr,n);
    int result =  (n-leftidx);
    printf("%d",result);
    return 0;
    

}