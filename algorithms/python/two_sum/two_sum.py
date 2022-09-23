##############################################################################
# Link: https://leetcode.com/problems/two-sum/
# Author: Kyle Hurd
##############################################################################

##############################################################################
# Problem: Two Sum
#
# Given an array of integers nums and an integer target,
# return indices of the two numbers such that they add up to target.
#  
# You may assume that each input would have exactly one solution,
# and you may not use the same element twice.
#  
# You can return the answer in any order. 
##############################################################################

############################################################################## 
# Example 1:
#  
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
#  
# Example 2:
#  
# Input: nums = [3,2,4], target = 6
# Output: [1,2]
#  
# Example 3:
#  
# Input: nums = [3,3], target = 6
# Output: [0,1]
##############################################################################

############################################################################## 
# Constraints:
#  
# - 2 <= nums.length <= 104
# - 109 <= nums[i] <= 109
# - 109 <= target <= 109
# - Only one valid answer exists.
##############################################################################

# Solution 1
# Time Complexity: O(n^2)
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i, val1 in enumerate(nums):
            for j, val2 in enumerate(nums[(i + 1):]):
                if val1 + val2 == target:
                    return [i,j + i + 1]
                
# Solution 2
# Time Complexity: O(n)
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        s = {}
        for i, num in enumerate(nums):
            if target - num in s:
                return [s[target - num], i]
            s[num] = i
        
        