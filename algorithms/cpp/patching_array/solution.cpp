#include <vector>
#include <algorithm>

class Solution {
public:
    int minPatches(const std::vector<int>& nums, const int n) {
        std::size_t missing{ 1 };
        int patches{};
        int index{};

        while (missing <= n) {
            if (index < nums.size() && nums.at(index) <= missing) {
                missing += nums.at(index);
                ++index;
            }
            else {
                missing += missing;
                ++patches;
            }
        }
        return patches;
    }
};
