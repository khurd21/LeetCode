#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int> g, std::vector<int> s) {

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        auto currentCookie{ s.begin() };
        int result{};
        for (auto childGreed : g) {

            currentCookie = std::find_if(currentCookie, s.end(), [childGreed](auto cookieSize) {
                return cookieSize >= childGreed;
            });

            if (currentCookie == s.end()) {
                break;
            }

            ++result;
            ++currentCookie;
        }

        return result;
    }
};
