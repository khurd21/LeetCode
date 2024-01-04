#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int numberOfBeams(const std::vector<std::string>& bank) {

        int prev{};
        int result{};
        
        for (const auto& s : bank) {
            const auto numLasers{ std::count(s.begin(), s.end(), '1') };

            if (numLasers == 0) {
                continue;
            }

            result += prev * numLasers;
            prev = numLasers;
        }

        return result;
    }
};