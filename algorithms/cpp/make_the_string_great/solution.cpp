#include <string>
#include <deque>

class Solution {
public:
    std::string makeGood(const std::string& s) {
        std::deque<char> q;
        for (const auto c : s) {
            if (!q.empty()) {
                const auto& top{ q.front() };
                if (std::tolower(top) == std::tolower(c) && top != c) {
                    q.pop_front();
                    continue;
                }
            }
            q.push_front(c);
        }
        return { q.crbegin(), q.crend() };
    }
};