#include <iostream>
#include <algorithm>

using namespace std;

void insertSort(int arr[],int n){
    int i , key , j;

    for (i = 1; i<n; i++){

        key = arr[i];

        j = i-1;

        while ( j >=0 && arr[j]> key){
            arr[j+1] = arr[j];

            j = j -1;
        }
        arr[j+1] = key;


    }
}

int main() {

    int arr[] = {3,2,7,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertSort(arr, n);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;

}
