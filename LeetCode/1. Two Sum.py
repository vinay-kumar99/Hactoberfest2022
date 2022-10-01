'''Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].'''



def twoSum(self, nums, target):
		buffer_dictionary = {}
		for i in rangenums.__len()):
			if nums[i] in buffer_dictionary:
				return [buffer_dictionary[nums[i]], i] #if a number shows up in the dictionary already that means the 
														#necesarry pair has been iterated on previously
			else: # else is entirely optional
				buffer_dictionary[target - nums[i]] = i 
				# we insert the required number to pair with should it exist later in the list of numbers
