#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::map<int, std::vector<int>> m;
        for (int index{}; index < arr.size(); ++index) {
            m[arr.at(index)].push_back(index);
        }
        std::vector<int> result(arr.size());
        int rank{ 1 };
        for (const auto& [key, indices] : m) {
            for (const auto index : indices) {
                result.at(index) = rank;
            }
            ++rank;
        }
        return result;
    }
};
