#include <cstdlib>
#include <utility>
#include <string>
#include <unordered_set>

namespace {

struct PairHash {
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& p) const {
        // Combine the hash values of the two elements using XOR
        return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
    }
}; // struct PairHash

} // namespace

class Solution {
public:
    bool isPathCrossing(const std::string& path) {
        std::unordered_set<std::pair<int, int>, PairHash> s;
        std::pair<int, int> direction{};
        s.insert(direction);
        for (char c : path) {
            if (c == 'N') {
                direction.first += 1;
            }
            else if (c == 'S') {
                direction.first -= 1;
            }
            else if (c == 'E') {
                direction.second += 1;
            }
            else if (c == 'W') {
                direction.second -= 1;
            }
            if (s.contains(direction)) {
                return true;
            }
            s.insert(direction);
        }

        return false;
    }
};