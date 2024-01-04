#include <unordered_map>
#include <vector>

class Solution {
public:
    int minOperations(const std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (const auto num : nums) {
            m[num] += 1;
        }

        int result{};
        for (auto [key, value] : m) {
            while (value % 3 != 0 && value > 1) {
                value -= 2;
                ++result;
            }
            if (value == 1) {
                return -1;
            }
            result += value / 3;
        }

        return result;
    }
};