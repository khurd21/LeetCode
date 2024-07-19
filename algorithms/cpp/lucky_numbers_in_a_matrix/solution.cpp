#include <vector>
#include <utility>

namespace {

auto find_minimum_row(const auto& row) {
    std::size_t index{};
    int value{ std::numeric_limits<int>::max() };
    for (std::size_t i{}; i < row.size(); ++i) {
        if (row.at(i) < value) {
            value = row.at(i);
            index = i;
        }
    }
    return std::make_pair(index, value);
}

auto find_maximum_col(const auto& matrix, const auto column) {
    std::size_t index{};
    int value{ std::numeric_limits<int>::min() };
    for (std::size_t i{}; i < matrix.size(); ++i) {
        if (matrix.at(i).at(column) > value) {
            value = matrix.at(i).at(column);
            index = i;
        }
    }
    return std::make_pair(index, value);
}

}

class Solution {
public:
    std::vector<int> luckyNumbers (const std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        for (std::size_t index{}; index < matrix.size(); ++index) {
            const auto& row{ matrix.at(index) };
            const auto index_value_row{ find_minimum_row(row) };
            const auto index_value_col{ find_maximum_col(matrix, index_value_row.first) };
            if (index_value_row.second == index_value_col.second) {
                result.push_back(index_value_row.second);
            }
        }
        return result;
    }
};
