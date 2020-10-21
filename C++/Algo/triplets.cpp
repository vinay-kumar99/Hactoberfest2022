//given a sorted array 
//find a triplet is presnt or not with given sum 

#include <iostream>
#include <algorithm>

using namespace std;




//sum = two pair + one 
//one = sum - twopair
bool isTrip(int arr[], int n, int sum){
    for(int i = 0; i < n-2; i++){


        int low = i +1;
        int high = n -1;
        while (low < high){
            if (arr[i] + arr[low] + arr[high] == sum){
                return true;
            }
            else if(arr[i] + arr[low]+ arr[high] > sum){
                high--;
            }
            else{
                low++;
            }
        }

       
        }
          return false;
    }
  



int main() {

    int arr[] = {2,3,4,8,9,20,40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int sum = 43;
    if (isTrip(arr, n, sum)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}