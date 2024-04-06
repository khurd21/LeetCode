#include <string>

class Solution {
public:
    int maxDepth(const std::string& s) {
        int result{};
        int count{};
        for (const auto c : s) {
            count += static_cast<int>(c == '(');
            count -= static_cast<int>(c == ')');
            result = std::max(count, result);
        }
        return result;
    }
};