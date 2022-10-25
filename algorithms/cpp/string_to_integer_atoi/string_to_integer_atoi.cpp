/* **********************************************************************
 * Link: https://leetcode.com/problems/string-to-integer-atoi/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: String to Integer (atoi)
 * 
 * Implement the myAtoi(string s) function, which converts a string to a
 * 32-bit signed integer (similar to C/C++'s atoi function).
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * Read in and ignore any leading whitespace.
 * Check if the next character (if not already at the end of the string)
 * is '-' or '+'. Read this character in if it is either. This determines
 * if the final result is negative or positive respectively. Assume the
 * result is positive if neither is present.
 * Read in next the characters until the next non-digit character or the end
 * of the input is reached. The rest of the string is ignored.
 * Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32).
 * If no digits were read, then the integer is 0. Change the sign as
 * necessary (from step 2).
 * If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
 * then clamp the integer so that it remains in the range. Specifically,
 * integers less than -231 should be clamped to -231, and integers greater
 * than 231 - 1 should be clamped to 231 - 1.
 * Return the integer as the final result.
 * 
 * Note:
 * 
 * Only the space character ' ' is considered a whitespace character.
 * Do not ignore any characters other than the leading whitespace or the
 * rest of the string after the digits.
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: s = "42"
 * Output: 42
 * Explanation: The underlined characters are what is read in, the caret
 * is the current reader position.
 * **********************************************************************
 */

#include <numeric>
#include <string>

class Solution {
public:
    
    int myAtoi(const std::string& s) const {
        
        bool is_negative = false;
        int result = 0;
        auto ptr = s.begin();
        
        while (ptr != s.end() && *ptr == ' ') {
            ++ptr;
        }
        
        if (ptr != s.end() && *ptr == '-') {
            is_negative = true;
            ++ptr;
        }
        else if (ptr != s.end() && *ptr == '+') {
            is_negative = false;
            ++ptr;
        }
        
        while (ptr != s.end() && *ptr >= '0' && *ptr <= '9') {
            const char c = *ptr;
            const int next_number = c - '0';
            
            if (is_overflow_mult(result, 10)) {
                return return_overflow(is_negative);
            }
             
            result *= 10;
            
           if (is_overflow_add(result, next_number)) {
                return return_overflow(is_negative);
            }
            
            result += next_number;
            ++ptr;
        }
        
        return is_negative ? -result : result;
    }
    
private:
    
    bool is_overflow_add(const int a, const int b) const {
        
        const int max_int = std::numeric_limits<int>::max();
        return (a) > (max_int - b);
    }
    
    bool is_overflow_mult(const int a, const int b) const {
        
        const int max_int = std::numeric_limits<int>::max();
        if (a > (max_int / b)) {
            return true;
        }
        return false;
    }
    
    int return_overflow(const bool is_negative) const {
        return is_negative ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    }
};