/* **********************************************************************
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Longest Palindromic Substring
 * 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * A string is called a palindrome string if the reverse of that string
 * is the same as the original string.
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: "babad"
 * Output: "aba"
 * Explanation: "aba" is a palindrome string.
 * 
 * Example 2:
 * 
 * Input: "cbbd"
 * Output: "bb"
 * **********************************************************************
*/

#include <string>

class Solution {
public:
    std::string longestPalindrome(const std::string& s) {

        if (s.length() < 2) {
            return s;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            
            const int len1 = expandAroundCenter(s, i, i);
            const int len2 = expandAroundCenter(s, i, i + 1);
            const int len = std::max(len1, len2);
            
            if (len > end - start) {
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }

        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};