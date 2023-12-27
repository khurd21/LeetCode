#include <string>
#include <unordered_map>

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const std::string s{ std::to_string(n) + "." + std::to_string(k) + "." + std::to_string(target) };
        if (m.contains(s)) {
            return m[s];
        }
        if (target < n || target > n * k) {
            return 0;
        }
        if (n == 1) {
            return target > k ? 0 : 1;
        }

        int result{};
        for (int i = 1; i <= k; ++i) {
            result = (result + numRollsToTarget(n - 1, k, target - i)) % 1'000'000'007;
        }

        m[s] = result;
        return result;
    }

private:

    std::unordered_map<std::string, int> m;
};