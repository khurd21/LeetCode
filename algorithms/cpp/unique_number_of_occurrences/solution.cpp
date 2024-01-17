#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(const std::vector<int>& arr) {

        std::unordered_map<int, int> m;
        std::unordered_set<int> s;
        for (auto value : arr) {
            m[value] += 1;
        }

        for (const auto& [key, value] : m) {
            if (s.contains(value)) {
                return false;
            }
            s.insert(value);
        }

        return true;
    }
};