//This is the algorithm for binary search if your arr is initially sorted and then rotated by some places
//Example search  0 in [4,5,6,7,0,1,2]

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return find(nums, target, 0, nums.size() - 1);
    }
    int find(vector<int> &nums, int target, int start, int end)
    {
        if (start > end)
            return -1;
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[end])
        {
            if (target > nums[mid] and target <= nums[end])
                return find(nums, target, mid + 1, end);
            return find(nums, target, start, mid - 1);
        }
        else
        {
            if (target >= nums[start] and target < nums[mid])
                return find(nums, target, start, mid - 1);
            return find(nums, target, mid + 1, end);
        }
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution s;
    cout << s.search(nums, target);
    return 0;
}