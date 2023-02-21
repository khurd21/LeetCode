/*
 * Given four integer arrays nums1, nums2, nums3, and nums4 all of length n,
 * return the number of tuples (i, j, k, l) such that:
 * 
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * Output: 2
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
 * 
 * Example 2:
 * 
 * Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * Output: 1
 * 
 * Constraints:
 * 
 * n == nums1.length
 * n == nums2.length
 * n == nums3.length
 * n == nums4.length
 * 1 <= n <= 200
 * -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    int fourSumCount(const std::vector<int>& nums1, const std::vector<int>& nums2,
                    const std::vector<int>& nums3, const std::vector<int>& nums4) {

        std::unordered_map<int, int> map;
        int result{};

        for (const auto value1 : nums1) {
            for (const auto value2 : nums2) {
                const auto sum{ value1 + value2 };
                map[sum] += 1;
            }
        }

        for (const auto value3 : nums3) {
            for (const auto value4 : nums4) {
                const auto sum { value3 + value4 };
                result += map[-sum];
            }
        }

        return result;
    }
};