/* **********************************************************************
 * Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
 * Author: Kyle Hurd
 * **********************************************************************
 * 
 * **********************************************************************
 * Problem: Check if the Sentence Is Pangram
 * 
 * A pangram is a sentence where every letter of the English alphabet
 * appears at least once.
 * 
 * Given a string sentence containing only lowercase English letters,
 * return true if sentence is a pangram, or false otherwise.
 * 
 * Example 1:
 * 
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
 * Output: true
 * Explanation: sentence contains at least one of every letter of the
 * English alphabet.
 * 
 * Example 2:
 * Input: sentence = "leetcode"
 * Output: false
 *
 * Constraints:
 * 
 * 1 <= sentence.length <= 1000
 * sentence consists of lowercase English letters.
 * **********************************************************************
 */

#include <string>
#include <set>

class Solution {
public:
    bool checkIfPangram(const std::string& sentence) {
        std::set<char> alphabet;

        for (const char character : sentence) {
            alphabet.insert(character);
            if (alphabet.size() == 26) {
                return true;
            }
        }
        
        return false;
    }
};