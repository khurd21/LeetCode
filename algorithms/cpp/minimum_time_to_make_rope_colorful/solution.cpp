#include <string>
#include <algorithm>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>

namespace {

struct Balloon {
    char color;
    int timeToRemove;
};

bool operator<(const Balloon& lhs, const Balloon& rhs) {
    if (lhs.color != rhs.color) {
        return lhs.color < rhs.color;
    }
    return lhs.timeToRemove < rhs.timeToRemove;
}

} // namespace

/// Solution 1
class Solution {
public:
    int minCost(const std::string& colors, const std::vector<int>& neededTime) {
        
        assert(colors.size() == neededTime.size());
        std::vector<Balloon> balloons;
        for (int i = 0; i < colors.size(); ++i) {
            balloons.push_back({colors[i], neededTime[i]});
        }

        std::vector<std::pair<int, int>> groups;
        for (int i = 0; i < balloons.size() - 1; ++i) {
            auto itr{ i + 1 };
            while (balloons[i].color == balloons[itr].color) {
                ++itr;
            }
            if (i < itr - 1) {
                groups.push_back({i, itr});
            }
            i = itr - 1;
        }

        int result{};
        for (const auto& [front, back] : groups) {
            std::sort(balloons.begin() + front, balloons.begin() + back);
            result += std::accumulate(balloons.begin() + front, balloons.begin() + back - 1, 0,
                [](const int prev, const auto& balloon) {
                    return prev + balloon.timeToRemove;
                }
            );
        }

        return result;
    }
};


/// Solution 2
class Solution {
public:
    int minCost(const std::string& colors, const std::vector<int>& neededTime) {
        
        assert(colors.size() == neededTime.size());
        assert(colors.size() > 0);

        std::vector<Balloon> balloons;
        for (int i = 0; i < colors.size(); ++i) {
            balloons.push_back({colors[i], neededTime[i]});
        }

        int result{};
        auto itemToSkip{ balloons[0] };
        for (int i = 0; i < balloons.size() - 1; ++i) {
            if (balloons[i].color == balloons[i+1].color) {
                result += std::min(itemToSkip.timeToRemove, balloons[i + 1].timeToRemove);
                itemToSkip = std::max(itemToSkip, balloons[i + 1]);
                continue;
            }
            itemToSkip = balloons[i + 1];
        }

        return result;
    }
};