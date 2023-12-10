#include <vector>

class Solution {
public:

    template <typename T>
    std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>>& matrix) {

        if (matrix.empty()) {
            return {};
        }

        std::vector<std::vector<T>> result(matrix[0].size(), std::vector<T>(matrix.size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};