#include <vector>
#include <limits>

namespace {

template <typename Container>
auto maxElement(auto x, auto y, Container&& container) {
    auto result{ std::numeric_limits<int>::min() };
    for (int i{ x }; i < x + 3; ++i) {
        for (int j{ y }; j < y + 3; ++j) {
            result = std::max(result, container.at(i).at(j));
        }
    }
    return result;
}

}

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(const std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<int>> result(grid.size() - 2, std::vector<int>(grid.size() - 2));
        for (int i{}; i < grid.size() - 2; ++i) {
            for (int j{}; j < grid.size() - 2; ++j) {
                result.at(i).at(j) = maxElement(i, j, grid);
            }
        }
        return result;
    }
};