//Selection Sort;;;

#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int n){

    int i , j , imin;

    for (i =0; i< n-1; i++){

        imin = i;

        for (j = i+1; j < n; j++){

            if (arr[j] < arr[imin]){

                imin = j;

                swap(arr[i], arr[imin]);

            }
        }
    }
}


int main() {

    int arr[] = {20,3,52,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);
    for (int i =0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}