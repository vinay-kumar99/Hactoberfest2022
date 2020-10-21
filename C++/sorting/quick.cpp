// Quick Sort//Partiaton method



#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int start , int end){


    int pivot = arr[end];
    int i = (start-1);

    for (int j = start; j <= end-1; j++){

        //if current elemnt is smaller than the pivot;
        if (arr[j] < pivot){
            i++;
            
            swap(arr[i], arr[j]);

        }

    }
    swap(arr[i+1],arr[end]);
   
    return (i+1);

}


void quicksort(int arr[], int start, int end){
    if(start < end){
        int pIndex = partition(arr, start, end);

        quicksort(arr, start, pIndex-1);
        quicksort(arr, pIndex+1,end);
    }
}


void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";

    }
    cout << endl;
}


int main() {
    int arr[] = {9 , 8 , 7, 6, 5 ,4 ,3 ,2 ,1};
    int n = sizeof(arr) / sizeof(arr[0]);


    quicksort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
