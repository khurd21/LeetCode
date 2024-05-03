#include <string>

namespace {

template <typename Iter>
Iter getNextNumber(Iter begin, Iter end, int& value) {
    Iter tmp{ begin };
    while (tmp < end) {
        if (*tmp == '.') {
            value = std::stoi(std::string(begin, tmp));
            return tmp + 1;
        }
        ++tmp;
    }
    value = std::stoi(std::string(begin, end));
    return end;
}

}

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        auto itr1{ version1.cbegin() };
        auto itr2{ version2.cbegin() };
        int num1{};
        int num2{};
        while (itr1 < version1.cend() && itr2 < version2.cend()) {
            itr1 = getNextNumber(itr1, version1.cend(), num1);
            itr2 = getNextNumber(itr2, version2.cend(), num2);
            if (num1 < num2) {
                return -1;
            }
            if (num2 < num1) {
                return 1;
            }
        }
        while (itr1 < version1.cend()) {
            itr1 = getNextNumber(itr1, version1.cend(), num1);
            if (num1 != 0) {
                return 1;
            }
        }
        while (itr2 < version2.cend()) {
            itr2 = getNextNumber(itr2, version2.cend(), num2);
            if (num2 != 0) {
                return -1;
            }
        }
        return 0;
    }
};