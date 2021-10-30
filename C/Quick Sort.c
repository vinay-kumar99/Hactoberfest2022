//Quicksort in C language

#include <stdio.h>
#include <conio.h>

void printArray();
void QuickSort();
int partition();
void swap();

void main ()
{   int n;
    printf ("Enter the size of the array: ");
    scanf("%d",&n);
    printf ("\nEnter the elements of the array: \n");
    int a[n];
    for (int x =0; x<n; x++)
    {
        scanf("%d", &a[x]);
    }
    
  QuickSort(a, 0, n - 1);
  
  printf("\nSorted Array in Ascending Order: \n");
  printArray(a, n);
}

void QuickSort(int a[], int i, int j){
  if (i < j) {
    

    int m = partition(a, i, j);
    
    QuickSort(a, i, m - 1);
    
    QuickSort(a, m + 1, j);
  }
}

int partition(int a[], int i, int j) {
  
  
  int pivot = a[j];
  
  
  int x = (i - 1);

  
  for (int y = i; y < j; y++) {
    if (a[y] <= pivot) {
    
      x++;
      

      swap(&a[x], &a[y]);
    }
  }
  
  swap(&a[x + 1], &a[j]);
  
  
  return (x + 1);
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}




void printArray(int a[], int n) {
  for (int x = 0; x < n; x++) 
    printf("%d  ", a[x]);
}





