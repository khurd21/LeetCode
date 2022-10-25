/* **********************************************************************
 * Link: https://leetcode.com/problems/reverse-integer/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Reverse Integer
 * 
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer
 * range [-231, 231 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers
 * (signed or unsigned).
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: x = 123
 * Output: 321
 * 
 * Example 2:
 * 
 * Input: x = -123
 * Output: -321
 * 
 * Example 3:
 * 
 * Input: x = 120
 * Output: 21
 * 
 * Example 4:
 * 
 * Input: x = 0
 * Output: 0
 * **********************************************************************
 */

#include <numeric>

class Solution {
public:
    
    const int max_int = std::numeric_limits<int>::max();
    const int min_int = std::numeric_limits<int>::min();
    
    int reverse(int x) const {
        
        int result = 0;
        
        while (x != 0) {
            
            const int next_number = x % 10; // work with negs?
            
            // check for overflows
            if (result >= 0 && next_number >= 0 && result > this->max_int - next_number) {
                return 0;
            }
            else if (result < 0 && next_number < 0 && result < this->min_int - next_number) {
                return 0;
            }
            else if (result >= 0 && result > this->max_int / 10) {
                return 0;
            }
            else if (result < 0 && result < this->min_int / 10) {
                return 0;
            }
            
            // compute result
            result *= 10;
            result += next_number;
            x /= 10;
        }
        return result;
    }
};