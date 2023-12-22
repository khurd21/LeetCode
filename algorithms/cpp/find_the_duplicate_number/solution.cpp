#include <vector>
#include <cmath>

class Solution {
public:
    int findDuplicate(std::vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i) {
            const auto itr{ std::abs(nums[i]) };
            auto& ref{ nums[itr] };
            if (ref < 0) {
                return itr;
            }
            ref = -ref;
        }

        return nums.size();
    }
};