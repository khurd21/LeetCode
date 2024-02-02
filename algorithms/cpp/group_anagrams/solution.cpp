#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        auto strsCopy = strs;
        for (auto& str : strsCopy) {
            std::sort(str.begin(), str.end());
        }

        std::unordered_map<std::string, std::vector<std::string>> m;
        for (int i = 0; i < strs.size(); ++i) {
            m[strsCopy[i]].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> result;
        for (auto& [key, value] : m) {
            result.emplace_back(std::move(value));
        }

        return result;
    }
};