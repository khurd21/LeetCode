#include <string>
#include <unordered_set>
#include <ranges>
#include <algorithm>

class Solution {
public:
    int partitionString(const std::string& s) {
        if (s.empty()) {
            return {};
        }
        
        int result{ 1 };
        std::unordered_set<char> us;
        std::ranges::for_each(std::as_const(s), [&](const auto c) {
            if (us.contains(c)) {
                us.clear();
                ++result;
            }
            us.insert(c);
        });
        return result;
    }
};
