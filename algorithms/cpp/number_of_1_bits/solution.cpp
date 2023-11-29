#include <cstdint>

class Solution {
public:
    int hammingWeight(std::uint32_t n) {
        // You can use std::bitset<>::count()
        int result{};
        while (n) {
            result += static_cast<int>(n & 1);
            n >>= 1;
        }
        return result;
    }
};