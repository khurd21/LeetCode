/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]


Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

- 2 <= nums.length <= 104
- 109 <= nums[i] <= 109
- 109 <= target <= 109
- Only one valid answer exists.
*/

namespace Problems;

public static class TwoSumSolution
{
    public static ICollection<int> TwoSum(in ICollection<int> nums, in int result)
    {
        List<int> resultIndices = new();
        Dictionary<int, int> numToIndex = new();

        for (var i = 0; i < nums.Count; i++)
        {
            int num = nums.ElementAt(i);
            int complement = result - num;

            if (numToIndex.ContainsKey(complement))
            {
                resultIndices.Add(numToIndex[complement]);
                resultIndices.Add(i);
                break;
            }

            numToIndex[num] = i;
        }

        return resultIndices;
        
    }
}
