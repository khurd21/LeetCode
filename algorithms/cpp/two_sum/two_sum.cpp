/* **********************************************************************
 * Link: https://leetcode.com/problems/two-sum/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Two Sum
 * 
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 * 
 * You can return the answer in any order. 
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Example 3:
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * **********************************************************************
 * 
 * **********************************************************************
 * Constraints:
 * 
 * - 2 <= nums.length <= 104
 * - 109 <= nums[i] <= 109
 * - 109 <= target <= 109
 * - Only one valid answer exists.
 * **********************************************************************
 */

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,std::vector<int>::iterator> my_map;
        
        for (auto itr = nums.begin(); itr < nums.end(); ++itr) {
            
            const int potential = target - *itr;
            
            if (my_map.find(potential) != my_map.end()) {
                return {
                    (int)(my_map[potential] - nums.begin()),
                    (int)(itr - nums.begin())
                };
            }
            
            my_map[*itr] = itr;
        }
        
        return {};
	}
};