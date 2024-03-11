#include <string>
#include <unordered_map>

class Solution {
public:
    std::string customSortString(const std::string& order, const std::string& s) {

        std::unordered_map<char, int> m;
        for (const auto c : s) {
            m[c] += 1;
        }

        std::string result;
        for (const auto c : order) {
            if (m.contains(c)) {
                result.append(std::string(m.at(c), c));
                m.erase(c);
            }
        }

        for (const auto& [key, value] : m) {
            result.append(std::string(value, key));
        }

        return result;
    }
};