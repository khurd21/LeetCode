#include <map>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string frequencySort(const std::string& s) {
        std::unordered_map<char, int> m;
        for (auto c : s) {
            m[c] += 1;
        }

        std::multimap<int, char, std::greater<int>> m1;
        for (const auto& [key, value] : m) {
            m1.insert({value, key});
        }

        std::string result;
        for (const auto& [key, value] : m1) {
            result += std::string(key, value);
        }

        return result;
    }
};