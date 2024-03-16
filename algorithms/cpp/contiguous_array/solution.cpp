#include <unordered_map>
#include <vector>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        
        if (nums.empty()) {
            return {};
        }

        int count{};
        int answer{};
        std::unordered_map<int, int> m;
        for (int i{}; i < nums.size(); ++i) {
            count += nums.at(i) ? 1 : -1;
            if (0 == count) {
                answer = i + 1;
            }
            else if (m.contains(count)) {
                answer = std::max(answer, i - m.at(count));
            }
            else {
                m.insert({count, i});
            }
        }

        return answer;
    }
};