#include <vector>
#include <algorithm>

class Solution {
public:
    auto findDuplicates(std::vector<int> nums) {
        decltype(nums) result;
        for (std::size_t i{}; i < nums.size(); ++i) {
            const auto itr{ std::abs(nums.at(i)) };
            auto& value{ nums.at(itr - 1) };
            if (value < 0) {
                result.push_back(itr);
            }
            value = -value;
        }
        return result;
    }
};