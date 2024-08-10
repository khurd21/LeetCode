#include <ranges>
#include <algorithm>

namespace {

auto isValid(const auto& grid, const auto i, const auto j) {
    std::unordered_set<int> s;
    s.insert(grid.at(i + 0).at(j + 0));
    s.insert(grid.at(i + 0).at(j + 1));
    s.insert(grid.at(i + 0).at(j + 2));
    s.insert(grid.at(i + 1).at(j + 0));
    s.insert(grid.at(i + 1).at(j + 1));
    s.insert(grid.at(i + 1).at(j + 2));
    s.insert(grid.at(i + 2).at(j + 0));
    s.insert(grid.at(i + 2).at(j + 1));
    s.insert(grid.at(i + 2).at(j + 2));
    if (s.size() != 9) {
        return false;
    }
    return std::ranges::all_of(std::as_const(s), [](const auto num) {
        return num < 10 && num > 0;
    });
}

auto isMagicSquare(const auto& grid, const auto i, const auto j) {
    if (i + 2 >= grid.size() || j + 2 >= grid.at(i).size()) {
        return false;
    }
    if (!isValid(grid, i, j)) {
        return false;
    }
    const auto sum{ grid.at(i).at(j) + grid.at(i).at(j + 1) + grid.at(i).at(j + 2) };
    return 
            grid.at(i + 0).at(j + 0) + grid.at(i + 0).at(j + 1) + grid.at(i + 0).at(j + 2) == sum &&
            grid.at(i + 1).at(j + 0) + grid.at(i + 1).at(j + 1) + grid.at(i + 1).at(j + 2) == sum &&
            grid.at(i + 2).at(j + 0) + grid.at(i + 2).at(j + 1) + grid.at(i + 2).at(j + 2) == sum &&

            grid.at(i).at(j + 0) + grid.at(i + 1).at(j + 0) + grid.at(i + 2).at(j + 0) == sum &&
            grid.at(i).at(j + 1) + grid.at(i + 1).at(j + 1) + grid.at(i + 2).at(j + 1) == sum &&
            grid.at(i).at(j + 2) + grid.at(i + 1).at(j + 2) + grid.at(i + 2).at(j + 2) == sum &&
            
            grid.at(i + 0).at(j) + grid.at(i + 1).at(j + 1) + grid.at(i + 2).at(j + 2) == sum &&
            grid.at(i + 2).at(j) + grid.at(i + 1).at(j + 1) + grid.at(i + 0).at(j + 2) == sum;
}

}

class Solution {
public:
    int numMagicSquaresInside(const std::vector<std::vector<int>>& grid) {
        int result{};
        for (std::size_t i{}; i < grid.size(); ++i) {
            for (std::size_t j{}; j < grid.at(i).size(); ++j) {
                result += static_cast<int>(isMagicSquare(grid, i, j));
            }
        }
        return result;
    }
};