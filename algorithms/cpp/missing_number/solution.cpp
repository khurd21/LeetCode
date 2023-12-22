#include <vector>
#include <numeric>
#include <cmath>

// SOLUTION 1: O(n) - Big and not necessary. This would be good
// if the numbers were not restrained.
class Solution {
public:
    int missingNumber(std::vector<int> nums) {
        bool zeroVisited{ false };
        for (int i = 0; i < nums.size(); ++i) {
            const auto itr{ std::abs(nums[i]) };
            if (itr < nums.size()) {
                auto& ref{ nums[itr] };
                ref = -1 * std::abs(ref);
                if (ref == 0) {
                    zeroVisited = true;
                }
            }
        }

        int result( nums.size() );
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result = i;
                break;
            }
            else if (nums[i] == 0 && !zeroVisited) {
                result = i;
                break;
            }
        }

        return result;
    }
};

// SOLUTION 2: Since the bounds are restrained, we can just:
// Both solutions have same time complexity
class Solution {
public:
    int missingNumber(const std::vector<int>& nums) {
        const auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        const auto size = static_cast<int>(nums.size());
        const auto potentialSum = (size * (size + 1)) / 2;
        return potentialSum - sum;
    }
};