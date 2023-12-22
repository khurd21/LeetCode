#include<string>
#include<algorithm>

class Solution {
public:
    int maxScore(const std::string& s) {

        int rhs( std::count(s.begin() + 1, s.end(), '1') );
        int lhs( std::count(s.begin(), s.begin() + 1, '0') );
        int max{ rhs + lhs };

        for (auto itr = s.begin() + 1; itr < s.end() - 1; ++itr) {
            lhs += *itr == '0';
            rhs -= *itr == '1';
            max = std::max(max, lhs + rhs);
        }

        return max;
    }
};