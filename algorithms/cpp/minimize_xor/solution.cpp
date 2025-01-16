class Solution {
public:
    int minimizeXor(int num1, int num2) {
        constexpr auto numBits = std::numeric_limits<int>::digits;
        std::bitset<numBits> bs2(num2);
        std::bitset<numBits> bs1(num1);
        auto count{bs2.count()};
        
        std::bitset<numBits> result;
        for (int i( numBits - 1 ); i >= 0; --i) {
            if (bs1[i] && count > 0) {
                result[i] = true;
                --count;
            }
        }
        for (int i{}; i < numBits; ++i) {
            if (!result[i] && count > 0) {
                result[i] = true;
                --count;
            }
        }

        return static_cast<int>(result.to_ulong());
    }
};