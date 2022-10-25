/* **********************************************************************
 * Link: https://leetcode.com/problems/zigzag-conversion/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: ZigZag Conversion
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given
 * number of rows like this: (you may want to display this pattern in a
 * fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string s, int numRows);
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * 
 * Example 3:
 * Input: s = "A", numRows = 1
 * Output: "A"
 * **********************************************************************
 */

#include <string>

class Solution {
public:
    std::string convert(const std::string& s, const int numRows) {

        if (numRows == 1) {
            return s;
        }

        const int size = 2 * numRows - 2;
        std::string result;
        result.reserve(s.size());

        for (int row = 0; row < numRows; ++row) {
            for (int i = row; i < s.size(); i += size) {

                result += s.at(i);

                if (row != 0 && row != numRows - 1) {
                    const int next = i + size - 2 * row;
                    if (next < s.size()) {
                        result += s.at(next);
                    }
                }
            }
        }
        return result;
    }
};