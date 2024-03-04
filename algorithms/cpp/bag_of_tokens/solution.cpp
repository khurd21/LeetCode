#include <vector>
#include <algorithm>

class Solution {
public:
    int bagOfTokensScore(std::vector<int> tokens, int power) {

        std::sort(tokens.begin(), tokens.end());

        int score{};
        int min{};
        int max( tokens.size() - 1 );
        int result{};

        while (min <= max) {
            if (tokens[min] <= power) {
                power -= tokens[min];
                ++score;
                result = std::max(result, score);
                ++min;
            }
            else if (score >= 1) {
                power += tokens[max];
                --score;
                --max;
            }
            else break;
        }
        return result;
    }
};