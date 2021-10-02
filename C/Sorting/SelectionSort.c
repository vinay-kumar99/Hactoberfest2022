#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){
    int temp=*x;
    *x = *y;
    *y = temp;
}
void selectionSort (int *arr, int n){
    int min = 0;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&arr[i],&arr[min]);
        }
    }
}
int main()
{
    int n;
    printf("Enter the size of Array : ");
    scanf("%d", &n);

    int *arr = (int *) malloc(sizeof(int)*(n+1));
    
    printf("Enter elements in Array : ");
    
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    selectionSort(arr,n);
    
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
