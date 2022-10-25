/* **********************************************************************
 * Link: https://leetcode.com/problems/palindrome-number/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Palindrome Number
 * 
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Follow up: Could you solve it without converting the integer to a string?
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: x = 121
 * Output: true
 * 
 * Example 2:
 * 
 * Input: x = -121
 * Output: false
 * 
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * 
 * Input: x = 10
 * Output: false
 * **********************************************************************
 * For not converting to a string, we can iterate through the first
 * half of the number, storing it in a list. Then we can iterate through
 * the second half of the number, comparing it to the list. If they are
 * not equal, then we know the number is not a palindrome.
 * 
 * Converting to a string seems ideal, as a string implementation
 * allows us to use this in almost any context. An integer is only a max
 * length of 10, so space is not a huge concern.
 */

#include <string>

class Solution {
public:
    bool isPalindrome(const int x) const {
        return this->isPalindrome(std::to_string(x));
    }
    
    bool isPalindrome(const std::string& s) const {
        
        auto front = s.begin();
        auto back = s.end() - 1;
        
        while (front < back) {
            
            if (*front != *back) {
                return false;
            }
            
            ++front;
            --back;
        }
        
        return true;
    }
};