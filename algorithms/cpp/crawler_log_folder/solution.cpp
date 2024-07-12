#include <algorithm>
#include <vector>

class Solution {
public:
    int minOperations(const std::vector<std::string>& logs) {
        int result{};
        std::ranges::for_each(std::as_const(logs), [&](const auto& log) {
            if (log == "./") {
                return;
            }
            result += log == "../" ? -1 : 1;
            result = std::max(result, 0);
        });
        return result;
    }
};
