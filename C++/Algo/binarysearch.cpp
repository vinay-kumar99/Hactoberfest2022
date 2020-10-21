#include <iostream>
#include <algorithm>

 //Recursive Approach 

 using namespace std;

// int bSearch(int arr[], int l, int h, int x){
//     if (l >= h){
//         return -1;

//     }
//     int mid = l+ (h-l)/2;//this is better than l+h/2

//     if (arr[mid] == x){
//         return mid;
//     }
//     else if (arr[mid] > x){
//         return bSearch(arr ,l, mid-1, x);

//     }
//     else{
//         return bSearch(arr,mid+1, h,x);

//     }

// }


//Iterative Approach 

int bSearch(int arr[], int n, int x){
    int l = 0;
    int h = n - 1;
   

    while(l <= h){
        int mid = l + (h-l)/2;
        if (arr[mid] == x){
            return mid;
        }
        else if (arr[mid] > x){
            h = mid - 1;

        }
        else {
            l = mid +1;
        }
 }

 return -1;


    


}
int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    
     cout << bSearch(arr,n,x);
    return 0;
}