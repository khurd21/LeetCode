#include <vector>

class Solution {
public:
    int minOperations(const std::vector<int>& nums, int k) {
        decltype(k) result{};
        decltype(k) r{};
        for (const auto num : nums) {
            r ^= num;
        }
        for (int i{}; i < 32; ++i) {
            const auto b1{ r & (1 << i) };
            const auto b2{ k & (1 << i) };
            result += static_cast<decltype(k)>(b1 != b2);
        }
        return result;
    }
};