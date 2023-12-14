#include <vector>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>> grid) {

        std::vector<int> rows(grid.size(), 0);
        std::vector<int> cols(grid[0].size(), 0);

        // Calculate rows
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }

        // Populating the Diff Matrix
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                const auto numOnesRow{ rows[i] };
                const auto numOnesCol{ cols[j] };
                const auto numZeroesRow{ static_cast<int>(grid[i].size() - numOnesRow) };
                const auto numZeroesCol{ static_cast<int>(grid.size() - numOnesCol) };
                grid[i][j] = numOnesRow + numOnesCol - numZeroesRow - numZeroesCol;
            }
        }
        
        return std::move(grid);
    }
};