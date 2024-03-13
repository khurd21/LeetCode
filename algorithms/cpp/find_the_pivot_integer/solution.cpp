class Solution {
public:
    int pivotInteger(const int n) {

        int x{ 1 };
        int lhs{};
        int rhs( (static_cast<double>(n) / 2) * (1 + n) );

        for (int x{ 1 }; x <= n; ++x) {
            lhs += x;
            if (lhs == rhs) {
                return x;
            }
            else if (lhs > rhs) {
                return -1;
            }
            rhs -= x;
        }

        return -1;
    }
};