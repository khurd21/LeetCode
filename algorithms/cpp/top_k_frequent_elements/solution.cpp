#include <vector>
#include <unordered_map>
#include <map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

        std::unordered_map<int, int> m;
        for (const auto num : nums) {
            m[num] += 1;
        }

        std::multimap<int, int, std::greater<int>> m1;
        for (const auto& [key, value] : m) {
            m1.insert({value, key});
        }

        std::vector<int> result;
        for (const auto& [key, value] : m1) {
            result.push_back(value);
        }
        
        return std::vector<int>(result.begin(), result.begin() + k);

    }
};