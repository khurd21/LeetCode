class Solution {
public:
    constexpr int passThePillow(const int n, const int time) {
        auto result{ 1 };
        auto flag{ false };
        for (int i{ 0 }; i < time; ++i) {
            result += flag ? -1 : 1;
            if (result == n || result == 1) {
                flag = !flag;
            }
        }
        return result;
    }
};
