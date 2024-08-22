class Solution {
public:
    int findComplement(int num) {
        bool one_found{};
        for (int i{ 31 }; i >= 0; --i) {
            const auto bit{ num & (1 << i) };
            if (!bit && !one_found) {
                continue;
            }
            one_found = true;
            num ^= 1 << i;
        }
        return num;
    }
};
