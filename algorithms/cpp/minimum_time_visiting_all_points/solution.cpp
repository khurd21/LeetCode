#include <vector>
#include <algorithm>

class Solution {
public:
    int minTimeToVisitAllPoints(const std::vector<std::vector<int>>& points) {
        int result{};
        auto start{ points.begin() };
        while (start < points.end() - 1) {

            const auto x1{ start->at(0) };
            const auto y1{ start->at(1) };

            ++start;

            const auto x2{ start->at(0) };
            const auto y2{ start->at(1) };

            result += std::max(std::abs(x1 - x2), std::abs(y1 - y2));
        }
        return result;
    }
};