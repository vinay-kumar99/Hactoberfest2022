//check if given sorted array is havinf pythagoras triplets or not 

#include <iostream>
#include <algorithm>

using namespace std;

bool isPy(int arr[],int n){

//creating a array with squares of its given elements 
    for (int i = 0; i < n; i++){
        arr[i ] = arr[i] * arr[i];
    }

    for (int i = n-1; i >= 2; i--){

        int l = 0; 
        int h = i-1;
        while (l < h){

            if (arr[l] + arr[h] == arr[i]){
                return true;
            }
            else if ( arr[l] + arr[h] > arr[i]){
                h--;
            }else {
                l++;
            }
        }
    }
    return false;


}

int main() {

    // int arr[] = {1,3,4,5,7};
    int arr[] = {1,2,3,4,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    isPy(arr,n) ? cout << "Yes" : cout << "No";
    return 0;

}