//SubArray of size k 
#include <iostream>
#include <algorithm>
using namespace std;

bool subK(int arr[], int n,int k,int gsum){
    int currentsum = 0;
    
    for (int i = 0; i < k; i++){
        currentsum += arr[i];
        
        if ( currentsum == gsum ){
            return true;
        }
    }
    for (int j = k; j <n; j++){
        currentsum = currentsum + arr[j] - arr[j-k];
        if (currentsum == gsum){
            return true;
        }
    }
    
    return false;

}

int main() {
    int arr[] = {1,4,2,10,2,3,1,0,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int sum = 18;
    if (subK(arr,n,k,sum)){
        cout << "Yes";
    }else{
        cout <<"NO";
    }
    return 0;
}