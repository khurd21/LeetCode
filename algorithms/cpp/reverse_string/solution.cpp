#include <vector>
#include <algorithm>


class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::ranges::reverse(s);
    }
};

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        auto front{ s.begin() };
        auto back{ s.end() - 1 };
        while (front < back) {
            std::swap(*front, *back);
            ++front;
            --back;
        }
    }
};