/* **********************************************************************
 * Link: https://leetcode.com/problems/number-of-matching-subsequences/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Number of Matching Subsequences
 * 
 * Given a string s and an array of strings words, return the number of
 * words[i] that is a subsequence of s.
 * 
 * A subsequence of a string is a new string generated from the original
 * string with some characters (can be none) deleted without changing
 * the relative order of the remaining characters.
 * 
 * For example, "ace" is a subsequence of "abcde".
 * **********************************************************************
 * 
 * **********************************************************************
 * Example 1:
 * 
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 * 
 * Example 2:
 * 
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 * **********************************************************************
 * 
 * **********************************************************************
 * Constraints:
 * 
 * 1 <= s.length <= 5 * 104
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 50
 * s and words[i] consist of only lowercase English letters.
 * **********************************************************************
 */

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numMatchingSubseq(const std::string& s, const std::vector<std::string>& words) {

        std::unordered_map<std::string, bool> already_calculated;
        int total = 0;

        for (const std::string& word : words) {

            if (auto search = already_calculated.find(word); search != already_calculated.end()) {
                if (search->second == true) {
                    ++total;
                }
                continue;
            }

            bool flag = true;
            auto front = s.begin();

            for (const char character : word) {
                front = std::find(front, s.end(), character);
                if (front == s.end()) {
                    flag = false;
                    break;
                }
                ++front;
            }

            if (flag == true) {
                ++total;
            }
            
            already_calculated.insert({word, flag});
        }

        return total;
    }
};