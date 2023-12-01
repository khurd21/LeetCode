#include <bitset>

namespace {

    int rightFillBits(int n) {
        std::bitset<32> b(n);
        int itr{};
        while (b[itr] != true) {
            b[itr] = true;
            ++itr;
        }

        return b.to_ulong();
    }
}

class Solution {
public:
    int minimumOneBitOperations(int n) {

        int result{};
        bool shouldAdd{ true };
        int mask{ 0x40000000 };

        while (mask) {
            int bit{ n & mask };
            int add{};
            
            if (bit) {
                const int value( rightFillBits(bit) );
                result += shouldAdd ? value : -value;
                shouldAdd = !shouldAdd;
            }

            mask >>= 1;
        }
        return result;
    }
};