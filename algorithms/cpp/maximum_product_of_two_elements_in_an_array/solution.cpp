#include <limits>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProduct(const std::vector<int>& nums) {
        int firstMax{ std::numeric_limits<int>::min() };
        int secondMax{ std::numeric_limits<int>::min() };

        for (const auto num : nums) {
            if (firstMax <= num) {
                secondMax = std::max(firstMax, secondMax);
                firstMax = num;
            }
            else {
                secondMax = std::max(num, secondMax);
            }
        }

        return (firstMax - 1) * (secondMax - 1);
    }
};