#include <vector>
#include <set>

class Solution {
public:
    long long maximumHappinessSum(const std::vector<int>& happiness, const int k) {
        std::multiset<int, std::greater<int>> s(happiness.cbegin(), happiness.cend());
        long long counter{};
        long long result{};
        for (const auto child : s) {
            const auto diff{ child - counter };
            if (diff <= 0 || counter >= k) {
                break;
            }
            result += diff;
            counter += 1;
        }
        return result;
    }
};