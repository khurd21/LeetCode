#include <cmath>

class Solution {
public:
    int totalMoney(int n) {
        const auto sum = [](int x, int y) -> int {
            return (static_cast<double>(x + y) / 2.0f) * (y - x + 1);
        };

        int numWeeks( std::floor(n / 7) );
        int remainder{ n % 7 };
        int total{ sum(numWeeks + 1, numWeeks + remainder) };

        for (int i = 1; i <= numWeeks; i += 1) {
            total += sum(i, i + 6);
        }
        return total;
    }
};