#include <array>
#include <map>

namespace {

constexpr std::array<std::array<int, 3>, 10> m {{
    {  4,  6, -1 },
    {  6,  8, -1 },
    {  9,  7, -1 },
    {  4,  8, -1 },
    {  0,  3,  9 },
    { -1, -1, -1 },
    {  0,  1,  7 },
    {  6,  2, -1 },
    {  1,  3, -1 },
    {  4,  2, -1 },
}};

std::map<std::pair<int, int>, int> cache;

}

class Solution {
public:
    int knightDialer(int n) {
        int ans{};
        for (int i = 0; i < 10; ++i) {
            ans = (ans + unique(n - 1, i)) % (1'000'000'007);
        }
        return ans;
    }

private:
    int unique(int n_left, int key) {

        if (key == -1) {
            return 0;
        }

        if (n_left < 1) {
            return 1;
        }

        if (cache.contains({n_left, key})) {
            return cache[{n_left, key}];
        }

        int ans{};
        for (const auto value : m[key]) {
            ans = (ans + unique(n_left - 1, value)) % (1'000'000'007);
        }

        cache[{n_left, key}] = ans;
        return ans;
    }
};