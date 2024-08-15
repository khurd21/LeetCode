#include <vector>
#include <ranges>
#include <algorithm>

namespace {

struct Bank {
    std::size_t fives{};
    std::size_t tens{};
    std::size_t twenties{};
};

}

class Solution {
public:
    bool lemonadeChange(const std::vector<int>& bills) {
        Bank bank;
        return std::ranges::all_of(std::as_const(bills), [&](const auto bill) {
            if (bill == 5) {
                bank.fives += 1;
                return true;
            }
            else if (bill == 10) {
                bank.tens += 1;
                if (bank.fives > 0) {
                    bank.fives -= 1;
                    return true;
                }
                return false;
            }
            else if (bill == 20) {
                bank.twenties += 1;
                if (bank.tens > 0 && bank.fives > 0) {
                    bank.tens -= 1;
                    bank.fives -= 1;
                    return true;
                }
                else if (bank.fives > 2) {
                    bank.fives -= 3;
                    return true;
                }
                return false;
            }
            return false;
        });
    }
};
