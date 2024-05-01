#include <string>
#include <algorithm>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        const auto itr{ std::find(word.begin(), word.end(), ch) };
        if (itr < word.end()) {
            std::reverse(word.begin(), itr + 1);
        }
        return word;
    }
};