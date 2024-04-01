#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        const auto first = std::find_if(s.crbegin(), s.crend(), [](const auto c) {
            return c != ' ';
        });
        const auto last = std::find(first, s.crend(), ' ');
        return std::abs(std::distance(first, last));
    }
};