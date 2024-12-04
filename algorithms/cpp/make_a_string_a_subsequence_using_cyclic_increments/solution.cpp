class Solution {
public:
    bool canMakeSubsequence(const std::string& str1, const std::string& str2) {
        constexpr auto A{ static_cast<int>('a') };
        auto itr2{ str2.cbegin() };
        auto itr1{ str1.cbegin() };
        while (itr1 < str1.cend() && itr2 < str2.cend()) {
            const auto n1{ static_cast<int>(*itr1) - A };
            const auto n2{ static_cast<int>(*itr2) - A };
            if (n1 == n2 || (n1 + 1) % 26 == n2) {
                ++itr2;
            }
            ++itr1;
        }
        return itr2 == str2.cend();
    }
};