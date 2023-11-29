#include <algorithm>
#include <string>

namespace {

constexpr char chair{ 'S' };
constexpr char plant{ 'P' };

template <typename Iter, typename Element>
constexpr Iter findSecondItem(Iter begin, Iter end, Element toSearch) noexcept {
    return std::find(std::next(std::find(begin, end, toSearch)), end, toSearch);
}

}

class Solution {
public:
    int numberOfWays(const std::string& corridor) {
        
        const int numberOfChairs( std::count(corridor.begin(), corridor.end(), chair) );
        const int numberOfPlants( std::count(corridor.begin(), corridor.end(), plant) );
        if (numberOfChairs % 2 == 1 || 0 == numberOfChairs) {
            return 0;
        }
        if (2 == numberOfChairs || 0 == numberOfPlants) {
            return 1;
        }

        int result{ 1 };
        auto front{ findSecondItem(corridor.begin(), corridor.end(), chair) };
        auto back{ std::find(std::next(front), corridor.end(), chair) };
        while (back != corridor.end()) {
            result = (result * std::distance(front, back)) % 1'000'000'007;

            front = std::find(std::next(back), corridor.end(), chair);
            back = std::find(std::next(front), corridor.end(), chair);
        }

        return result;
    }
};