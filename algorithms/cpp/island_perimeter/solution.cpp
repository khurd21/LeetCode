#include <vector>

class Solution {
public:
    int islandPerimeter(const std::vector<std::vector<int>>& grid) {
        int perimeter{};
        for (int i{}; i < grid.size(); ++i) {
            for (int j{}; j < grid.at(i).size(); ++j) {
                if (!grid.at(i).at(j)) {
                    continue;
                }
                perimeter += static_cast<int>(i == 0);
                perimeter += static_cast<int>(i == grid.size() - 1);
                perimeter += static_cast<int>(j == 0);
                perimeter += static_cast<int>(j == grid.at(i).size() - 1);
                perimeter += static_cast<int>(grid.at(i - (i != 0)).at(j) == 0);
                perimeter += static_cast<int>(grid.at(i).at(j - (j != 0)) == 0);
                perimeter += static_cast<int>(grid.at(i + (i != grid.size() - 1)).at(j) == 0);
                perimeter += static_cast<int>(grid.at(i).at(j + (j != grid.at(i).size() - 1)) == 0);
            }
        }
        return perimeter;
    }
};