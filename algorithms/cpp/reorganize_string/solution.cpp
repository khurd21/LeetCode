#include <string>
#include <unordered_map>
#include <queue>

namespace {

struct Count {
    char letter;
    int count;
};

bool operator<(const Count& lhs, const Count& rhs) {
    return lhs.count < rhs.count;
}

} // namespace

class Solution {
public:
    std::string reorganizeString(std::string s) {

        std::unordered_map<char, int> m;
        for (auto c : s) {
            m[c] += 1;
        }
        std::priority_queue<Count> pq;
        for (const auto [letter, count] : m) {
            pq.push({ letter, count });
        }

        int itr{};
        while (!pq.empty()) {
            auto top{ pq.top() };
            pq.pop();
            for (int i = 0; i < top.count; ++i) {
                if (itr >= s.size()) {
                    itr = 1;
                }
                s[itr] = top.letter;
                itr += 2;
            }
        }

        // Need to check that the value is good
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                return {};
            }
        }

        return s;
    }
};