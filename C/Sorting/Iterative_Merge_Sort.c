#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void merge(int arr[],int l,int mid,int h)
{
    int i =l,j = mid+1,k =l;
    int auxi[100];
    while(i <=mid && j <=h)
    {
        if(arr[i] < arr[j])
            auxi[k++] = arr[i++];
        else
            auxi[k++] = arr[j++];
    }
    while(i <= mid){
        auxi[k++] = arr[i];
        i++;
    }
        
    while(j <= h){
        auxi[k++] = arr[j];
        j++;
    }
    
    for(i =l; i <=h; i++)
        arr[i] = auxi[i];
}
void iterativeMergeSort(int arr[] , int n)
{
    int p,l,h,mid,i;
    for(p = 2; p <= n; p = p*2)
    {
        for(i = 0; i+p-1 <= n; i = i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(arr,l,mid,h);
        }
    }
    if(p/2 < n){
        merge(arr,0,p/2-1,n);
    }
}
int main()
{
    int n;
    
    printf("Enter the size of Array : ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter elements in Array : ");
    for(int i =0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    iterativeMergeSort(arr, n);
    
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");
 
    return 0;
}
