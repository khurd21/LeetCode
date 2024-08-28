#include <vector>

namespace {

auto isSubIsland(auto& grid1, auto& grid2, auto i, auto j, auto& answer) {
    if (grid1.size() <= i) {
        return;
    }
    if (i < 0) {
        return;
    }
    if (grid1.at(i).size() <= j) {
        return;
    }
    if (j < 0) {
        return;
    }

    auto& square1{ grid1.at(i).at(j) };
    auto& square2{ grid2.at(i).at(j) };
    if (square1 == 0 && square2 == 1) {
        answer = false;
    }
    if (square2 == 1) {
        square2 = -1;
    }
    else {
        return;
    }
    isSubIsland(grid1, grid2, i + 0, j + 1, answer);
    isSubIsland(grid1, grid2, i + 1, j + 0, answer);
    isSubIsland(grid1, grid2, i - 0, j - 1, answer);
    isSubIsland(grid1, grid2, i - 1, j - 0, answer);
}

}

class Solution {
public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        int result{};
        for (std::size_t i{}; i < grid1.size(); ++i) {
            for (std::size_t j{}; j < grid1.at(i).size(); ++j) {
                const auto& square2{ grid2.at(i).at(j) };
                if (square2 != 1) {
                    continue;
                }
                auto isIsland{ true };
                isSubIsland(grid1, grid2, i, j, isIsland);
                result += static_cast<int>(isIsland);
            }
        }
        return result;
    }
};
