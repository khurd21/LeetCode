#include <vector>
#include <algorithm>

namespace {

void divide(std::vector<int>& nums) {
    auto front{ nums.begin() };
    auto back{ nums.end() - 1 };

    while (front < back) {
        if (*back <= 0) {
            --back;
        }
        else if (*front > 0) {
            ++front;
        }
        else {
            std::swap(*front, *back);
        }
    }
}

}

class Solution {
public:
    int firstMissingPositive(std::vector<int> nums) {
        divide(nums);
        const int size = std::count_if(nums.begin(), nums.end(), [](const auto num) -> bool {
            return num > 0;
        });
        
        for (int i = 0; i < size; ++i) {
            const auto value{ std::abs(nums[i]) };
            if (value - 1 < size && nums[value - 1] > 0) {
                nums[value - 1] = -nums[value - 1];
            }
        }

        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return size + 1;
    }
};