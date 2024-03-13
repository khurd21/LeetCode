#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, const int target) {

        int lhs{};
        int rhs( numbers.size() - 1 );

        while (lhs < rhs) {
            const auto sum{ numbers[lhs] + numbers[rhs] };
            if (sum == target) {
                return { lhs + 1, rhs + 1 };
            }
            else if (sum < target) {
                ++lhs;
            }
            else {
                --rhs;
            }
        }

        return {};
    }
};