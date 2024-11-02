class Solution {
public:
    std::string makeFancyString(const std::string& s) {
        std::string result;
        int count{};
        char prev{ s.at(0) };
        for (const auto c : s) {
            if (c == prev && count < 2) {
                ++count;
                result += c;
            }
            else if (c != prev) {
                result += c;
                count = 1;
            }
            prev = c;
        }
        return result;
    }
};
