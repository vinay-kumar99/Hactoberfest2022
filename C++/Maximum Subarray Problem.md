## QUESTION : Maximum Subarray
```
Given an integer array nums, 
find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Constraints :
1 <= nums.length <= 105
-10 4 <= nums[i] <= 104
```
>**Approach for Largest Sum Contiguous Subarray by using Kadane’s Algorithm**

>**Time Complexity : O(N) where N is the size of the given array** <br>
>**Space Complexity : O(1)**

```
#include<bits/stdc++.h>
using namespace std;

int max_SubArraySum(int nums[], int size)
{
    int currentMax = INT_MIN, tempMax = 0;
 
    for (int i = 0; i < size; i++)
    {
        tempMax = tempMax + nums[i];
        if (currentMax < tempMax)
            currentMax = tempMax;
 
        if (tempMax < 0)
            tempMax = 0;
    }
    return currentMax;
}
int main() {
   int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
   int n = sizeof(nums)/sizeof(nums[0]);
   
   int max_sum = max_SubArraySum(nums, n);
   cout << "Maximum Contiguous Array Sum is " << max_sum;
   return 0;
}
```
