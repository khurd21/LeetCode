#include <limits>

class Solution {
public:
    static constexpr int nthUglyNumber(const int n) {
        int count{};
        for (int i{ 1 }; i < std::numeric_limits<int>::max(); ++i) {
            count += static_cast<int>(isUgly(i));
            if (count == n) {
                return i;
            }
        }
        return -1;
    }

private:
    static constexpr bool isUgly(int num) {
        if (num <= 0) return false;
        
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        
        return num == 1;
    }
};
