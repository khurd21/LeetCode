#include <algorithm>
#include <vector>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        int result{};
        for (int i{}; i < seats.size(); ++i) {
            result += std::abs(students.at(i) - seats.at(i));
        }
        return result;
    }
};