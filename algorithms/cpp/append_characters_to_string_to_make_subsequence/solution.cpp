#include <string>

class Solution {
public:
    int appendCharacters(const std::string& s, const std::string& t) {
        auto t_itr{ t.cbegin() };
        for (const auto c : s) {
            if (t_itr < t.cend() && *t_itr == c) {
                ++t_itr;
            }
        }
        return static_cast<int>(t.cend() - t_itr);
    }
};