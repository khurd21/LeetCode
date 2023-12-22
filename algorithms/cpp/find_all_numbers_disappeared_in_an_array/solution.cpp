#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(const std::vector<int>& nums) {
        std::vector<int> result(nums.size());
        std::iota(result.begin(), result.end(), 1);

        for (auto num : nums) {
            result[num - 1] = -1;
        }

        result.erase(std::remove(result.begin(), result.end(), -1), result.end());
        return result;
    }
};