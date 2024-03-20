#include <algorithm>
#include <vector>

namespace {

bool isIntersection(const std::vector<int>& p1, const std::vector<int>& p2) {
    return p1.at(1) >= p2.at(0) && p1.at(0) <= p2.at(1);
}

}

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto& p1, const auto& p2) { return p1[0] < p2[0]; });
        auto prev{ points[0] };
        int result{ 1 };
        for (const auto& point : points) {
            if (!isIntersection(prev, point)) {
                ++result;
                prev = point;
            }
            prev.at(0) = std::max(prev.at(0), point.at(0));
            prev.at(1) = std::min(prev.at(1), point.at(1));
        }
        return result;
    }
};