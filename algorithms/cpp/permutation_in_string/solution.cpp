class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        std::multiset<char> ms(s1.cbegin(), s1.cend());
        int left{};
        int right{};
        while (right < s2.size()) {
            if (ms.empty()) {
                return true;
            }
            if (ms.contains(s2.at(right))) {
                ms.erase(ms.find(s2.at(right)));
                ++right;
                continue;
            }
            if (left == right) {
                ++left; ++right;
            }
            else {
                ms.insert(s2.at(left));
                ++left;
            }

        }
        return ms.empty();
    }
};
