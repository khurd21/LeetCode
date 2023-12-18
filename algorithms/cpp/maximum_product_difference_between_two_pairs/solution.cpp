#include <limits>
#include <array>
#include <vector>

namespace {
    constexpr auto minimum{ std::numeric_limits<int>::min() };
    constexpr auto maximum{ std::numeric_limits<int>::max() };
}

class Solution {
public:
    int maxProductDifference(const std::vector<int>& nums) {
        std::array<int, 4> values = { minimum, minimum, maximum, maximum };
        for (auto num : nums) {
            if (num > values[0]) {
                values[1] = values[0];
                values[0] = num;
            }
            else if (num > values[1]) {
                values[1] = num;
            }

            if (num < values[3]) {
                values[2] = values[3];
                values[3] = num;
            }
            else if (num < values[2]) {
                values[2] = num;
            }
        }

        return (values[0] * values[1]) - (values[3] * values[2]);
    }
};