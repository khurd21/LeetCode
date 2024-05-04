#include <vector>
#include <set>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::multiset<int> s(people.cbegin(), people.cend());
        int result{};
        auto itr{ s.begin() };
        while (s.size()) {
            const auto itr{ s.begin() };
            const auto value{ *itr };
            const auto match{ limit - value };

            ++result;
            s.erase(itr);

            if (value == limit) {
                continue;
            }
            const auto matchItr{ s.find(match) };
            if (matchItr != s.end()) {
                s.erase(matchItr);
                continue;
            }
            const auto lowerBoundItr{ s.lower_bound(match) };
            if (lowerBoundItr != s.begin() && *std::prev(lowerBoundItr) + value <= limit) {
                s.erase(std::prev(lowerBoundItr));
            }
            else if (lowerBoundItr != s.end() && *lowerBoundItr + value <= limit) {
                s.erase(lowerBoundItr);
            }
        }
        return result;
    }
};