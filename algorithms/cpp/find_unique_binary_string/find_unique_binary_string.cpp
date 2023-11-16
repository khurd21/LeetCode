/*
Given an array of strings nums containing n unique binary strings each of length n,
return a binary string of length n that does not appear in nums. If there are multiple
answers, you may return any of them.

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

Constraints:

- n == nums.length
- 1 <= n <= 16
- nums[i].length == n
- nums[i] is either '0' or '1'.
- All the strings of nums are unique.
*/

#include <string>
#include <bitset>
#include <algorithm>
#include <vector>

// First Attempt
class Solution {
public:
    std::string findDifferentBinaryString(const std::vector<std::string>& nums) {

        constexpr int sizeBitSet{ 16 };
        const int bitLength{ static_cast<int>(nums[0].size()) };
        
        std::bitset<sizeBitSet> b; b.set();
        for (int i = 0; i < b.to_ulong(); ++i) {
            std::bitset<sizeBitSet> tmp(i);
            const auto s{ tmp.to_string().substr(sizeBitSet - bitLength, bitLength) };
            if (std::find(nums.begin(), nums.end(), s) == nums.end()) {
                return s;
            }
        }
        return {};
    }
};

// Many Attempts Later
class Solution {
public:
    std::string findDifferentBinaryString(const std::vector<std::string>& nums) {

        std::string result;
        for (int i = 0; i < nums.size(); ++i) {
            bool toggle = nums[i][i] - '0';
            result += std::to_string(!toggle);
        }
        return result;
    }
};