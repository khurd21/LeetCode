#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {
        int result{ -1 };
        std::unordered_map<char, int> firstSeen;
        
        for (int i{}; i < s.size(); ++i) {
            if (!firstSeen.contains(s[i])) {
                firstSeen[s[i]] = i;
            }
        }

        for (int i{}; i < s.size(); ++i) {
            if (firstSeen.contains(s[i])) {
                const auto distance{ i - firstSeen[s[i]] -1 };
                result = std::max(result, distance);
            }
        }

        return result;
    }
};