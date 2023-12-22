#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int buyChoco(const std::vector<int>& prices, int money) {
        int first{ std::numeric_limits<int>::max() };
        int second{ std::numeric_limits<int>::max() };
        for (auto price : prices) {
            if (first > price) {
                second = first;
                first = price;
            }
            else {
                second = std::min(second, price);
            }
        }

        int leftover{ money - (first + second) };
        return leftover >= 0 ? leftover : money;
    }
};