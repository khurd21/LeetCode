#include <vector>

namespace {

void markChunk(auto& grid, auto i, auto j) {
    if (i >= grid.size() || j >= grid.at(i).size()
        || i < 0 || j < 0) {
        return;
    }
    auto& item{ grid.at(i).at(j) };
    if (item == '0' || item == '2') {
        return;
    }
    item = '2';
    markChunk(grid, i + 1, j);
    markChunk(grid, i, j + 1);
    markChunk(grid, i - 1, j);
    markChunk(grid, i, j - 1);
}

}

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> grid) {
        int result{};
        for (int i{}; i < grid.size(); ++i) {
            for (int j{}; j < grid.at(i).size(); ++j) {
                if (grid.at(i).at(j) == '1') {
                    ++result;
                    markChunk(grid, i, j);
                }
            }
        }
        return result;
    }
};