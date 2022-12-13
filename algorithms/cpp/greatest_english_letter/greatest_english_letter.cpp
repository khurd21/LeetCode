/* **********************************************************************
 * Link: https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Description:
 * 
 * Given a string of English letters s, return the greatest English letter
 * which occurs as both a lowercase and uppercase letter in s. The
 * returned letter should be in uppercase. If no such letter exists,
 * return an empty string.
 * 
 * An English letter b is greater than another letter a if b appears after a in the English alphabet.
 * 
 * Example 1:
 * 
 * Input: s = "lEeTcOdE"
 * Output: "E"
 * Explanation:
 * The letter 'E' is the only letter to appear in both lower and upper case.
 * 
 * Example 2:
 * 
 * Input: s = "arRAzFif"
 * Output: "R"
 * Explanation:
 * The letter 'R' is the greatest letter to appear in both lower and upper case.
 * Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
 * 
 * Example 3:
 * 
 * Input: s = "AbCdEfGhIjK"
 * Output: ""
 * Explanation:
 * There is no letter that appears in both lower and upper case.
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 1000
 * s consists of lowercase and uppercase English letters.
*/

#include<string>

class Solution {
public:
    std::string greatestLetter(const std::string& s) {

        const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (auto itr = alphabet.rbegin(); itr < alphabet.rend(); ++itr) {

            const char lower = std::tolower(*itr);
            const char upper = std::toupper(*itr);

            const auto lower_ptr = std::find(s.begin(), s.end(), lower);
            const auto upper_ptr = std::find(s.begin(), s.end(), upper);

            if (lower_ptr != s.end() && upper_ptr != s.end()) {
                std::string result;
                result += upper;
                return result;
            }
        }
        return "";
    }
};