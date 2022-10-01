class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        maxtillnow=0
        c=0
        for i in range(0,len(nums),1):
            if nums[i]==1:
                c=c+1
                maxtillnow=max(maxtillnow,c)
            else:
                maxtillnow=max(maxtillnow,c)
                c=0
        return maxtillnow
