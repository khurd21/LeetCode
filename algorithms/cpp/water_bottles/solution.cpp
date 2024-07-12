class Solution {
public:
    constexpr int numWaterBottles(int numBottles, const int numExchange) {
        int result{};
        while (numBottles - numExchange >= 0) {
            numBottles -= numExchange;
            numBottles += 1;
            result += numExchange;
        }
        result += numBottles;
        return result;
    }
};
