/* **********************************************************************
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without
 * repeating characters.
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence
 * and not a substring.
 * **********************************************************************
 * 
 * **********************************************************************
 * Constraints:
 * 
 * - 0 <= s.length <= 5 * 104
 * - s consists of English letters, digits, symbols and spaces.
 * **********************************************************************
 */

#include <string>
#include <set>
#include <limits>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        
        if (s.size() <= 1) {
            return s.size();
        }
        
        int max = std::numeric_limits<int>::min();
        std::set<char> set;
        int front = 0;
        int back = 0;
        
        while (back < s.size()) {
            if (set.count(s[back]) == 1) {
                
                while (front < back && s[front] != s[back]) {
                    set.erase(s[front]);
                    ++front;
                }
                ++front;
            }
            
            set.insert(s[back]);
            max = std::max(max, int(set.size()));
            ++back;
        }
        
        return max;
    }
};