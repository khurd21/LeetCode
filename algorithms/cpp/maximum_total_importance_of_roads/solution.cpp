#include <vector>
#include <set>

class Solution {
public:
    long long maximumImportance(int n, const std::vector<std::vector<int>>& roads) {
        // 2: 4 - 5 * 4 = 20
        // 1: 3 - 4 * 3 = 12
        // 3: 2 - 3 * 2 = 6
        // 0: 2 - 2 * 2 = 4
        // 4: 1 - 1 * 1 = 1
        // Sum: 43

        // 1. Count the number of occurrences of each city
        // 2. Sort it.
        // 3. Starting at n = 5, multiply largest count with n. n-- until it is 0.

        std::vector<long long> sums(n);
        for (const auto& road : roads) {
            sums.at(road.at(0)) += 1;
            sums.at(road.at(1)) += 1;
        }
        // std::sort(sums.begin(), sums.end(), std::greater());
        std::multiset<long long, std::greater<long long>> s(sums.cbegin(), sums.cend());
        long long result{};
        for (const auto sum : s) {
            result += sum * n;
            --n;
        }
        return result;
    }
};
