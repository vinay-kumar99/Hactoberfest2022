//Maximum Sum of  k Consecutive Elements
#include <iostream>
#include <algorithm>
using namespace std;


int maxSum(int arr[],int n,int k){
    int maxValue = 0;
    int currentsum = 0;
    
    for (int i = 0; i < n; i++){
        currentsum += arr[i];
        if (i >= k-1){
            maxValue = max(maxValue, currentsum);
            currentsum -= arr[i - (k-1)];


        }

    }
    return maxValue;

}

int main() {
    
    int arr[] = {5,2,-1,0,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << maxSum(arr,n,k) << endl;
    return 0;
}