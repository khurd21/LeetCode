#include <set>
#include <vector>

class Solution {
public:
    int minIncrementForUnique(const std::vector<int>& nums) {
        std::multiset<int> ms(nums.cbegin(), nums.cend());
        std::set<int> s;
        for (const auto num : ms) {
            if (s.contains(num)) {
                auto back{ s.end() };
                std::advance(back, -1);
                s.insert(*back + 1);
                continue;
            }
            s.insert(num);
        }

        int result{};
        auto ms_itr{ ms.cbegin() };
        auto s_itr{ s.cbegin() };
        while (ms_itr != ms.cend() && s_itr != s.cend()) {
            result += std::abs(*s_itr - *ms_itr);
            ++ms_itr;
            ++s_itr;
        }
        return result;
    }
};