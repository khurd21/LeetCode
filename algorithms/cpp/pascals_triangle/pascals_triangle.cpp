/*
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * Example 1:
 * 
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * Example 2:
 * 
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * Constraints:
 * 
 * 1 <= numRows <= 30
 */

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(const int num_rows) {
        
        std::vector<std::vector<int>> result(num_rows);
        result[0] = std::vector<int>{ 1 };

        for (int row{ 1 }; row < num_rows; ++row) {

            const auto& prev{ result[row - 1] };
            auto& curr{ result[row] };

            curr.push_back(1);
            for (int j{ 1 }; j < row; ++j) {
                curr.push_back(prev[j] + prev[j - 1]);
            }
            curr.push_back(1);
            
        }
        return result;
        
    }
};