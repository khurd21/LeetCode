class Solution {
public:
    int maxMoves(const std::vector<std::vector<int>>& grid) {
        std::map<std::pair<int, int>, int> cache;
        int result{};
        for (int i{}; i < grid.size(); ++i) {
            result = std::max(result, maxMovesHelper(i, 0, -1, grid, cache));
        }
        return result;
    }

private:
    int maxMovesHelper(int row, int col, int prev, const std::vector<std::vector<int>>& grid, std::map<std::pair<int, int>, int>& cache) {
        if (row >= grid.size()) {
            return -1;
        }
        if (col >= grid.at(row).size()) {
            return -1;
        }
    
        const auto current{ grid.at(row).at(col) };
        if (prev >= current) {
            return -1;
        }

        if (cache.contains({row, col})) {
            return cache.at({row, col}) - 1;
        }

        const auto up{ 1 + maxMovesHelper(row + 1, col + 1, current, grid, cache) };
        const auto right{ 1 + maxMovesHelper(row + 0, col + 1, current, grid, cache) };
        const auto down{ 1 + maxMovesHelper(row - 1, col + 1, current, grid, cache) };
        cache[{row, col}] = std::max({up, right, down});
        return cache.at({row, col});
    }
};
