#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

class Solution {
public:
    int leastInterval(const std::vector<char>& tasks, const int n) {
        auto max_frequency{ std::numeric_limits<int>::min() };
        std::unordered_map<char, int> counts;
        for (const auto task : tasks) {
            counts[task] += 1;
            max_frequency = std::max(max_frequency, counts.at(task));
        }

        const auto max_count{ std::count_if(counts.cbegin(), counts.cend(), [max_frequency](const auto& pair) {
            return max_frequency == pair.second;
        }) };

        const auto time{ static_cast<int>((max_frequency - 1) * (n + 1) + max_count) };
        return std::max(time, static_cast<int>(tasks.size()));
    }
};