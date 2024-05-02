#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int findMaxK(const std::vector<int>& nums) {
        int result{ -1 };
        std::unordered_set<int> s(nums.cbegin(), nums.cend());
        for (const auto num : s) {
            s.insert(num);
            if (num < 0) {
                continue;
            }
            if (s.contains(-num)) {
                result = std::max(result, num);
            }
        }
        return result;

    }
};


class Solution {
public:
    int findMaxK(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());

        int left{};
        int right( nums.size() - 1 );
        while (left < right) {
            const auto leftValue{ nums.at(left) };
            const auto rightValue{ nums.at(right) };
            if (-leftValue == rightValue) {
                return rightValue;
            }
            if (-leftValue < rightValue) {
                --right;
            }
            else {
                ++left;
            }
        }
        return -1;
    }
};