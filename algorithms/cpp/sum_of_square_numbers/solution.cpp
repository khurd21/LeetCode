#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        int b{};
        auto b_squared{ std::pow(b, 2) };
        while (b_squared <= c) {
            const auto a{ std::sqrt(c - b_squared) };
            if (static_cast<int>(a) == a) {
                return true;
            }
            ++b;
            b_squared = std::pow(b, 2);
        }
        return false;
    }
};
