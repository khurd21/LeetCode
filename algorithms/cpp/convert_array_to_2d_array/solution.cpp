#include <vector>
#include <algorithm>

namespace {

template <typename Matrix>
void insertToMatrix(Matrix&& matrix, int row, int value) {
    while (row >= matrix.size()) {
        matrix.push_back({});
    }
    matrix[row].push_back(value);
}

} // namespace

class Solution {
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int> nums) {

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int currentIndex{};

        for (int i = 0; i < nums.size() - 1; ++i) {
            insertToMatrix(result, currentIndex, nums[i]);
            currentIndex += nums[i] == nums[i + 1] ? 1 : -currentIndex;
        }
        
        insertToMatrix(result, currentIndex, *(nums.end() - 1));
        return result;
    }
};