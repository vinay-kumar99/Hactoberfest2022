//Given a sorted array and a sum, find if there is pair which 
//sum is equal to sum.
//ex - {1,2,4,5,8} x = 7 ... answer is yes x can befound in array with pair

#include <iostream>
#include <algorithm>

using namespace std;

bool isPair(int arr[], int n, int x){

    int low = 0;
    int high = n-1;
    while (low < high){

        if (arr[low] + arr[high] == x){
            return true;
        }
        else if(arr[low] + arr[high]> x){
            high--;
        }
        else if(arr[low] + arr[high] < x){
            low++;
        }
    }
    return false;


}

int main() {
    int arr[] = {2,4,8,9,11,12,20,30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;
    if (isPair(arr, n , x)){
        cout << "yes";
    }
    else{
        cout << "NO";
}
    return 0;
}