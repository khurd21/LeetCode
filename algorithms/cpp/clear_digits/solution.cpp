class Solution {
public:
    std::string clearDigits(const std::string& s) {
        std::string result;
        for (const auto c : s) {
            if (std::isdigit(c)) {
                result.pop_back();
            }
            else {
                result += c;
            }
        }
        return result;
    }
};
