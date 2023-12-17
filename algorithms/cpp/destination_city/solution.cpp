#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::string destCity(const std::vector<std::vector<std::string>>& paths) {

        std::unordered_set<std::string> s;
        for (const auto& path : paths) {
            const auto& start{ path[0] };
            s.insert(start);
        }

        std::string result;
        for (const auto& path : paths) {
            const auto& end{ path[1] };
            if (!s.contains(end)) {
                result = end;
                break;
            }
        }

        return result;
    }
};