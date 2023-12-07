#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestOddNumber(const std::string& num) {
        auto itr = std::find_if(num.rbegin(), num.rend(), [](auto c) { return (c - '0') % 2; });
        if (itr != num.rend()) {
            return std::string(num.begin(), itr.base());
        }
        return {};
    }
};