#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        swap(&arr[min_index], &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    int arr[] = {2, 13, 8, 1, 5};
    int n = sizeof(arr) / sizeof(int);
    
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}
