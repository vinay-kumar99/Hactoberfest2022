// Bubble Sort ///

#include <iostream>

#include <algorithm>
using namespace std;

void bubbleSort(int arr[] , int n){

    bool flag;

    for (int i = 0; i < n-1; i++){
        flag = false;
        for (int j = 0; j < n-i-1; j++){


            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }

        if (flag == false){
            break;
        }
    }
}

int main(){
    int arr[] = {20,5,15,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}