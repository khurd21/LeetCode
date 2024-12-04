class Solution {
public:
    std::string addSpaces(const std::string& s, const std::vector<int>& spaces) {
        std::string result;
        int position{};
        for (const auto& index : spaces) {
            auto substr{ s.substr(position, index - position) };
            position = index;
            result += substr + ' ';
        }
        auto substr{ s.substr(position, s.size()) };
        result += substr;
        return result;
    }
};