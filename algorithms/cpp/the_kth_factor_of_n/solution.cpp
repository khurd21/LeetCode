class Solution {
public:
    constexpr static int kthFactor(const int n, const int k) {
        int num_factors{};
        for (int i{ 1 }; i <= n; ++i) {
            if (n % i != 0) {
                continue;
            }
            ++num_factors;
            if (num_factors == k) {
                return i;
            }
        }
        return -1;
    }
};
