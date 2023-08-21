#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        constexpr int illegal{ std::numeric_limits<int>::min() };
        int current{ nums[0] };
        int times_seen{};

        for (int& num : nums) {
            if (current == num) {
                ++times_seen;
                if (times_seen > 2) {
                    num = illegal;
                }
            }
            else {
                times_seen = 1;
                current = num;
            }
        }
        
        const int number_gone(
            std::count_if(nums.begin(), nums.end(), [illegal](const int num){
                return num == illegal;
            })
        );

        for (auto i = nums.begin(); i < nums.end(); ++i) {
            if (*i == illegal) {
                auto j = std::find_if(i, nums.end(), [illegal](const int value) {
                    return value != illegal;
                });
                if (j != nums.end()) {
                    std::swap(*i, *j);
                }
            }
        }
        return nums.size() - number_gone;
    }
};