/* **********************************************************************
 * Link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
 * Author: Kyle Hurd
 * **********************************************************************
 * Description: An n x n matrix is valid if every row and every column
 * contains all the integers from 1 to n (inclusive).
 * 
 * Given an n x n integer matrix matrix, return true if the matrix is valid.
 * Otherwise, return false.
 * 
 * Example 1:
 * 
 * Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
 * Output: true
 * Explanation: In this case, n = 3, and every row and column contains
 * the numbers 1, 2, and 3.
 * 
 * Hence, we return true.
 * 
 * Example 2:
 * 
 * Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
 * Output: false
 * Explanation: In this case, n = 3, but the first row and the first
 * column do not contain the numbers 2 or 3.
 * 
 * Hence, we return false.
 * 
 * Constraints:
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * 1 <= matrix[i][j] <= n 
 */

#include<vector>
#include<unordered_set>

class Solution {
public:
    bool checkValid(const std::vector<std::vector<int>>& matrix) {

        const int n = matrix.size();
        for (const auto& row : matrix) {

            fill_numbers(numbers, n);
            for (const int value : row) {
                numbers.erase(value);
            }

            if (numbers.size() > 0) {
                return false;
            }
        }

        for (int i = 0; i < n; ++i) {

            fill_numbers(numbers, n);
            for (int j = 0; j < n; ++j) {
                numbers.erase(matrix[j][i]);
            }

            if (numbers.size() > 0) {
                return false;
            }
        }

        return true;
    }

private:
    std::unordered_set<int> numbers;

    static void fill_numbers(std::unordered_set<int>& s, const int n) {
        s.clear();
        for (int i = 1; i <= n; ++i) {
            s.insert(i);
        }
    }
};