//return floor of or given number if not perfect square root . 
// ex- 4 - answer is 2
//ex - 12 - answer is 3

#include <iostream>
#include <algorithm>
using namespace std;

int sqroot(int n){

    if (n == 0 || n == 1){
        return 0;
    }
    int ans;
    int low = 1;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;

        if (mid <= n/mid){
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid -1;
            
        }
    }
    return ans;


}

int main() {
    int n = 16;
    cout << sqroot(n);
    return 0;
}