/*
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following three operations permitted on a word:
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * Example 1:
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * Example 2:
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * Constraints:
 * 
 * 0 <= word1.length, word2.length <= 500
 * word1 and word2 consist of lowercase English letters.
 */

#include <string>
#include <vector>

class Solution {
public:
    int minDistance(const std::string& word1, const std::string& word2) {

        std::vector<std::vector<int>> dp(word1.length() + 1, std::vector<int>(word2.length() + 1));

        for (int i = 0; i < dp[0].size(); ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i < word1.length() + 1; ++i) {
            for (int j = 1; j < word2.length() + 1; ++j) {
                if (word1[i - 1] != word2[j - 1]) {
                    dp[i][j] = std::min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
                }
                else {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};