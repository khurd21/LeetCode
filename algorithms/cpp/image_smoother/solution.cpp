#include <vector>

namespace {

template <typename Matrix, typename Index>
decltype(auto) smooth(Matrix&& matrix, Index x, Index y) {

    using ElementType = typename std::remove_reference<decltype(matrix[x][y])>::type;

    static_assert(std::is_integral<Index>::value, "Index must be an integral type");

    // Assuming your matrix elements are numeric (int, float, etc.)
    ElementType sum{};

    const Index numRows = matrix.size();
    const Index numCols = matrix[0].size();

    const Index startX = (x > 0) ? x - 1 : x;
    const Index endX = (x < numRows - 1) ? x + 1 : x;
    const Index startY = (y > 0) ? y - 1 : y;
    const Index endY = (y < numCols - 1) ? y + 1 : y;

    // Sum the values of the center and surrounding edges
    for (Index i = startX; i <= endX; ++i) {
        for (Index j = startY; j <= endY; ++j) {
            sum += matrix[i][j];
        }
    }

    // Calculate the average
    Index numElements = (endX - startX + 1) * (endY - startY + 1);
    return sum / static_cast<ElementType>(numElements);
}

}

class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        std::vector<std::vector<int>> result(img.size(), std::vector<int>(img[0].size()));
        for (int i = 0; i < img.size(); ++i) {
            for (int j = 0; j < img[i].size(); ++j) {
                result[i][j] = smooth(img, i, j);
            }
        }
        return result;
    }
};