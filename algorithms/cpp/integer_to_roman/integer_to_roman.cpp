/* **********************************************************************
 * Link: https://leetcode.com/problems/integer-to-roman/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Integer to Roman
 * 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C,
 * D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, 2 is written as II in Roman numeral, just two one's added
 * together. 12 is written as XII, which is simply X + II. The number 27 is
 * written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to
 * right. However, the numeral for four is not IIII. Instead, the number
 * four is written as IV. Because the one is before the five we subtract it
 * making four. The same principle applies to the number nine, which is
 * written as IX. There are six instances where subtraction is used:
 * 
 * - I can be placed before V (5) and X (10) to make 4 and 9.
 * - X can be placed before L (50) and C (100) to make 40 and 90.
 * - C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * Given an integer, convert it to a roman numeral.
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: num = 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * Input: num = 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * Input: num = 9
 * Output: "IX"
 * **********************************************************************
 */

#include <string>
#include <array>

class Solution {
public:

    static inline std::array<std::pair<int, std::string>, 13> roman = {
        std::make_pair(1000, "M"),
        std::make_pair(900, "CM"),
        std::make_pair(500, "D"),
        std::make_pair(400, "CD"),
        std::make_pair(100, "C"),
        std::make_pair(90, "XC"),
        std::make_pair(50, "L"),
        std::make_pair(40, "XL"),
        std::make_pair(10, "X"),
        std::make_pair(9, "IX"),
        std::make_pair(5, "V"),
        std::make_pair(4, "IV"),
        std::make_pair(1, "I")
    };

    std::string intToRoman(int num) const {

        std::string result = "";
        auto ptr = this->roman.begin();
        
        while (num > 0 && ptr != this->roman.end()) {
            
            int div = num / ptr->first;
            num %= ptr->first;
            
            while (div > 0) {
                result += ptr->second;
                --div;
            }
            
            ++ptr;
        }
        
        return result;
    }
};