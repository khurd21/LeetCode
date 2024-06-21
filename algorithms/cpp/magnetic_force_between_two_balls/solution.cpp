#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int> position, int m) {
        // if size == 2
        // return min(position) - max(position);
        // else
        std::sort(position.begin(), position.end());
        const auto check = [](const auto& positions, const auto min_distance, const auto m) {
            int count{ 1 };
            auto previous_position{ positions.at(0) };
            for (int i{ 1 }; i < positions.size(); ++i) {
                const auto current_position{ positions.at(i) };
                if (current_position - previous_position >= min_distance) {
                    previous_position = current_position;
                    ++count;
                }
            }
            return count >= m;
        };

        int low{ 1 };
        int high{ position.back() };
        while (low < high) {
            const auto middle{ (low + high + 1) / 2 };
            if (check(position, middle, m)) {
                low = middle;
            }
            else {
                high = middle - 1;
            }
        }
        return low;
    }
};
