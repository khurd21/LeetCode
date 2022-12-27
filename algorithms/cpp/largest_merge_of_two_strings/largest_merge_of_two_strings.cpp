/* **********************************************************************
 * Link: https://leetcode.com/problems/largest-merge-of-two-strings/
 * Author: Kyle Hurd
 * **********************************************************************
 * You are given two strings word1 and word2. You want to construct
 * a string merge in the following way: while either word1 or word2
 * are non-empty, choose one of the following options:
 * 
 * If word1 is non-empty, append the first character in word1 to
 * merge and delete it from word1.
 * 
 * For example, if word1 = "abc" and merge = "dv", then after
 * choosing this operation, word1 = "bc" and merge = "dva".
 * 
 * If word2 is non-empty, append the first character in word2 to
 * merge and delete it from word2.
 * 
 * For example, if word2 = "abc" and merge = "", then after choosing
 * this operation, word2 = "bc" and merge = "a".
 * 
 * Return the lexicographically largest merge you can construct.
 * 
 * A string a is lexicographically larger than a string b
 * (of the same length) if in the first position where a and b differ,
 * a has a character strictly larger than the corresponding character
 * in b. For example, "abcd" is lexicographically larger than "abcc"
 * because the first position they differ is at the fourth character,
 * and d is greater than c.
 * 
 * Example 1:
 * 
 * Input: word1 = "cabaa", word2 = "bcaaa"
 * Output: "cbcabaaaaa"
 * Explanation: One way to get the lexicographically largest merge is:
 * 
 * - Take from word1: merge = "c", word1 = "abaa", word2 = "bcaaa"
 * - Take from word2: merge = "cb", word1 = "abaa", word2 = "caaa"
 * - Take from word2: merge = "cbc", word1 = "abaa", word2 = "aaa"
 * - Take from word1: merge = "cbca", word1 = "baa", word2 = "aaa"
 * - Take from word1: merge = "cbcab", word1 = "aa", word2 = "aaa"
 * - Append the remaining 5 a's from word1 and word2 at the end of merge.
 * 
 * Example 2:
 * 
 * Input: word1 = "abcabc", word2 = "abdcaba"
 * Output: "abdcabcabcaba"
 * 
 * Constraints:
 * 
 * 1 <= word1.length, word2.length <= 3000
 * word1 and word2 consist only of lowercase English letters.
 */

#include<string>

// C++17
// std::string_view
class Solution {
public:
    std::string largestMerge(std::string_view word1, std::string_view word2) {

        std::string result;
        
        while ((word1.empty() || word2.empty()) == false) {

            if (word1.compare(word2) > 0) {
                result += word1.at(0);
                word1.remove_prefix(1);
            }
            else {
                result += word2.at(0);
                word2.remove_prefix(1);
            }
        }

        if (word1.empty() == false) {
            result.append(word1);
        }

        if (word2.empty() == false) {
            result.append(word2);
        }
        
        return result;
    }
};

// C++11
// std::string::iterator
class Solution {
public:
    std::string largestMerge(const std::string& word1, const std::string& word2) {
        
        std::string result;
        auto ptr1{ word1.begin() };
        auto ptr2{ word2.begin() };

        while (ptr1 != word1.end() && ptr2 != word2.end()) {
            if (*ptr1 == *ptr2) {
                auto t1{ ptr1 };
                auto t2{ ptr2 };

                while (t1 != word1.end() && t2 != word2.end() && *t1 == *t2) {
                    ++t1;
                    ++t2;
                }
                
                if (*t1 > *t2) {
                    result += *ptr1;
                    ++ptr1;
                }
                else {
                    result += *ptr2;
                    ++ptr2;
                }

            }
            else if (*ptr1 > *ptr2) {
                result += *ptr1;
                ++ptr1;
            }
            else {
                result += *ptr2;
                ++ptr2;
            }
        }

        if (ptr1 != word1.end()) {
            result += std::string(ptr1, word1.end());
        }

        if (ptr2 != word2.end()) {
            result += std::string(ptr2, word2.end());
        }

        return result;
    }
};