#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int maxFrequencyElements(const std::vector<int>& nums) {

        std::unordered_map<int, int> m;
        for (auto num : nums) {
            m[num] += 1;
        }

        std::multimap<int, int> mm;
        auto maximum{m.begin()->second};
        for (const auto& [key, value] : m) {
            maximum = std::max(maximum, value);
            mm.insert({ value, key});
        }

        const auto count{ mm.count(maximum) };
        return count * maximum;
    }
};