#include <string>
#include <algorithm>

class Solution {
public:
    std::string maximumOddBinaryNumber(const std::string& s) {
        const auto numOnes = std::count(s.cbegin(), s.cend(), '1');
        const auto numZeroes = std::count(s.cbegin(), s.cend(), '0');

        std::string result;
        result.append(numOnes - 1, '1');
        result.append(numZeroes, '0');
        
        return result + '1';
    }
};