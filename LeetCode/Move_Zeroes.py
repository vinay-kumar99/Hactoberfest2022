class Solution(object):
    def moveZeroes(self, nums):
        for i in range(len(nums)):
            if nums[i]==0:
                k=i
                break
        if i==len(nums)-1:
            return nums
                
        i=k
        j=k+1
        while i< len(nums) and  j< len(nums):
            if (nums[j]!=0):
                temp=nums[i]
                nums[i]=nums[j]
                nums[j]=temp
                i=i+1
            j=j+1
        return nums
