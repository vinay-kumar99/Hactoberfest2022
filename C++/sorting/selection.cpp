#include <iostream>
using namespace std;
 
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
 
void selectionSort(int arr[], int n)
{
   int min_index;
  
   for (int i = 0; i < n-1; i++)
   {
       min_index = i;
       for (int j = i+1; j < n; j++)
       {
           if (arr[j] < arr[min_index])
               min_index = j;
       }
       swap(&arr[min_index], &arr[i]);
   }
}
 
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
       cout << arr[i] << " ";
   cout << "\n";
}
 
int main()
{
   int arr[] = {6, 3, 8, 9, 5};
   int n = sizeof(arr)/sizeof(arr[0]);
  
   cout << "Given Array: ";
   printArray(arr, n);
  
   selectionSort(arr, n);
  
   cout << "Sorted Array: ";
   printArray(arr, n);
  
   return 0;
}
