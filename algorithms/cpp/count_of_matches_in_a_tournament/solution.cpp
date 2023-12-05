// Approach 1 - not seeing the pattern
class Solution {
public:
    int numberOfMatches(int n) {
        int result{};
        while (n > 1) {
            bool isOdd{ n % 2 == 1 };
            result += (n - isOdd) / 2;
            n = (n - isOdd) / 2 + isOdd;
        }
        return result;
    }
};

// Approach 2 - seeing the pattern
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};