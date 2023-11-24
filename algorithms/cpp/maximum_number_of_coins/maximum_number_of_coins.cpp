#include <algorithm>
#include <vector>

class Solution {
public:
    int maxCoins(std::vector<int> piles) {
        std::sort(piles.begin(), piles.end());

        int result{};
        auto front{ piles.begin() };
        auto back{ piles.end() - 2 };

        while (front < back) {
            result += *back;
            ++front;
            back -= 2;
        }

        return result;
    }
};