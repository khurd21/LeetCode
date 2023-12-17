#include <array>
#include <string>

class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        // Use unordered_map to support all unicode characters
        std::array<int, 26> a{};
        for (char c : s) {
            a[static_cast<int>(c - 'a')] += 1;
        }
        for (char c : t) {
            a[static_cast<int>(c - 'a')] -= 1;
        }
        for (auto v : a) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }
};

