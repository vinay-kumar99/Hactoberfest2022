// Leetcode question link :- https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int imt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if (nums[i] == nums[i+1])
            {
                imt = nums[i];
                break;
            }
        }
        
        return imt;
            
        
    }
};
