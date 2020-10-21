//Find the number of occurence of a given number 


#include <iostream>
#include <algorithm>


using namespace std;


// use binary search 

int find(int arr[], int n, int x, bool leftmost){
    int low = 0; 
    int high = n-1;
    int mid = (high + low )/2;
    int res = -1;

    while (low <= high){
        
        if (arr[mid] == x){
            res = mid;

            if (leftmost){  // it flag is true we will find the left most 
                high = mid - 1;
            }else{             //else we will find the right most 
                low = mid+1;
            }

        }
        if (arr[mid] > x){
            high = mid - 1;
            
        }
        else{
            low = mid +1;
        }
        mid = (low+high)/2;
    }
    return res;
}


 int main() {
     int arr[] = {2,2,3,3,3,3};
     int n = sizeof(arr) / sizeof(arr[0]);
     int x;
     cout << "Enter the number "<< endl;
     cin >> x;
     int leftidx = find(arr, n, x, true); // pasing true find the left most index
     int rightidx = find(arr, n, x,false); // this will find the right most index 

     cout << (rightidx - leftidx) + 1;
   return 0;
 }