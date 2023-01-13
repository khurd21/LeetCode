/* **********************************************************************
 * Link: https://leetcode.com/problems/max-consecutive-ones/
 * Author: Kyle Hurd
 * **********************************************************************
 * Given a binary array nums, return the maximum number of consecutive
 * 1's in the array.
 * 
 * Example 1:
 * 
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are
 * consecutive 1s. The maximum number of consecutive 1s is 3.
 * 
 * Example 2:
 * 
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 105
 * nums[i] is either 0 or 1.
 */

#include<vector>

class Solution {
public:
    int findMaxConsecutiveOnes(const std::vector<int>& nums) {

        int max_consecutive_ones{ 0 };
        int counter{ 0 };

        for (const int num : nums) {
            counter = num == 1 ? counter + 1 : 0;
            max_consecutive_ones = std::max(max_consecutive_ones, counter);
        }

        return max_consecutive_ones;
    }
};