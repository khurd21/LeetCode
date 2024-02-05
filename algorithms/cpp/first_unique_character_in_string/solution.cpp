#include <unordered_map>
#include <string>

class Solution {
public:
    int firstUniqChar(const std::string& s) {
        std::unordered_map<char, int> m;
        for (auto c : s) {
            m[c] += 1;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};