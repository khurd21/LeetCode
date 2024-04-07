#include <string>
#include <algorithm>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::size_t count{};
        const auto f = [&](const auto c, const auto left_cmp, const auto right_cmp) {
            if (count == 0 && c == left_cmp) {
                return true;
            }
            count += static_cast<decltype(count)>(c == right_cmp);
            count -= static_cast<decltype(count)>(c == left_cmp);
            return false;
        };
        
        s.erase(std::remove_if(s.begin(), s.end(), [&](const auto c) {
            return f(c, ')', '(');
        }), s.end());
        count = 0;
        s.erase(s.begin(), std::remove_if(s.rbegin(), s.rend(), [&](const auto c) {
            return f(c, '(', ')');
        }).base());
        return s;
    }
};