//merge Sort 

/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
  void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int left =l;
         int right=m+1;
         vector<int>temp;
         
         while(left<=m && right<=r){
             if(arr[left]>arr[right])
             {
                 temp.push_back(arr[right]);
                 right++;
             }
             else{
                 temp.push_back(arr[left]);
                 left++;
             }
         }
         while(left<=m){
             temp.push_back(arr[left]);
                 left++;
         }
         while(right<=r){
             temp.push_back(arr[right]);
                 right++;
         }
         for(int i=l; i<=r; i++){
             arr[i]=temp[i-l];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l == r) return;
int m=(l+r)>>1;
mergeSort(arr,l,m);
mergeSort(arr,m+1,r);
merge(arr,l,m,r);
    }
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
