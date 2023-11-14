/*
Given a string s, return the number of unique palindromes of length three that are a
subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still
only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some
characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 
Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

- 3 <= s.length <= 105
- s consists of only lowercase English letters.
*/

#include <unordered_map>
#include <unordered_set>
#include <string>

class Solution {
public:
    int countPalindromicSubsequence(const std::string& s) {
        
        std::unordered_map<char, int> first_occurrence;
        std::unordered_map<char, int> last_occurrence;

        for (int i{}; i < s.size(); ++i) {
            last_occurrence[s[i]] = i;
        }

        for (int i(s.size() - 1); i >= 0; --i) {
            first_occurrence[s[i]] = i;
        }

        int result{};
        for (const auto& [key, first] : first_occurrence) {
            const auto& last = last_occurrence[key];

            // Is there a character in between the first and last?
            if (last - first < 2) {
                continue;
            }

            const auto front{ s.begin() + first + 1 };
            const auto back{ s.begin() + last };
            std::unordered_set<char> unique_characters(s.begin() + first + 1, s.begin() + last);
            result += static_cast<int>(unique_characters.size());
        }

        return result;
    }
};