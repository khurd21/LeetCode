#include <string>

namespace {

auto removeSubstring(auto& input, const std::string& substring) {
    const auto originalSize{ input.size() };
    auto position{ input.begin() };
    while (position + substring.size() <= input.end()) {
        const auto value{ std::string(position, position + substring.size()) };
        if (value == substring) {
            position = input.erase(position, position + substring.size());
            if (position != input.begin()) {
                --position;
            }
            continue;
        }
        ++position;
    }
    return static_cast<int>(originalSize - input.size()) / 2;
}

}

class Solution {
public:
    int maximumGain(std::string s, const int x, const int y) {
        if (y >= x) {
            const auto baRemoved{ removeSubstring(s, "ba") };
            const auto abRemoved{ removeSubstring(s, "ab") };
            return baRemoved * y + abRemoved * x;
        }
        const auto abRemoved{ removeSubstring(s, "ab") };
        const auto baRemoved{ removeSubstring(s, "ba") };
        return baRemoved * y + abRemoved * x;
    }
};
