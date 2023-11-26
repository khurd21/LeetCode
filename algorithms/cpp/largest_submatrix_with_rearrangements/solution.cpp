#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
        if (matrix.size() < 1) {
            return -1;
        }

        int result{};
        std::vector<int> height(matrix[0].size(), 0);
        for (const auto& row : matrix) {

            for (auto j = 0; j < row.size(); ++j) {
                height[j] += row[j] == 0 ? -height[j] : 1;
            }

            auto tmp_height(height);
            std::sort(tmp_height.begin(), tmp_height.end());
            for (auto j = 0; j < row.size(); ++j) {
                result = std::max(result, tmp_height[j] * static_cast<int>(row.size() - j));
            }
        }

        return result;
    }
};