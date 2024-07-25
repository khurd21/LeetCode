#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        std::ranges::for_each(std::as_const(nums), [&](const auto num) {
            m[num] += 1;
        });
        std::vector<std::pair<int, int>> v;
        std::ranges::for_each(std::as_const(m), [&v](const auto& pair) {
            const auto& num{ pair.first };
            const auto& count{ pair.second };
            for (int i{}; i < count; ++i) {
                v.emplace_back(num, count);
            }
        });
        std::sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
            if (rhs.second == lhs.second) {
                return rhs.first < lhs.first;
            }
            return lhs.second < rhs.second;
        });
        std::vector<int> result(v.size());
        std::transform(v.cbegin(), v.cend(), result.begin(), [](const auto& pair) {
            return pair.first;
        });
        return result;
    }
};
