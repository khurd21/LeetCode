#include <vector>

class Solution {
public:
    double averageWaitingTime(const std::vector<std::vector<int>>& customers) {
        std::size_t count{};
        std::size_t clock{};
        for (const auto& customer : customers) {
            if (clock < customer.at(0)) {
                clock = customer.at(0);
            }
            const auto wait_time{ clock - customer.at(0) + customer.at(1) };
            count += wait_time;
            clock += customer.at(1);
        }
        return static_cast<double>(count) / customers.size();
    }
};
