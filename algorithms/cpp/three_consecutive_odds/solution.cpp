#include <vector>

class Solution {
public:
    bool threeConsecutiveOdds(const std::vector<int>& arr) {
        constexpr auto numOfConsecutiveOdds{ 3 };
        int count{};
        for (const auto value : arr) {
            if (value % 2 == 0) {
                count = 0;
                continue;
            }

            ++count;
            if (count >= numOfConsecutiveOdds) {
                return true;
            }
        }
        return false;
    }
};
