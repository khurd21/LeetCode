#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestGoodInteger(const std::string& num) {

        std::string result{};
        int result_as_int{};
        
        for (auto itr{ num.begin() }; itr < num.end() - 2; ++itr) {
            const auto substring{ std::string(itr, itr + 3) };
            const auto value{ std::stoi(substring) };
            const auto are_equal{
                std::all_of(substring.begin(), substring.end(), [&](char c) {
                    return c == substring[0];
                })
            };

            if (are_equal && value >= result_as_int) {
                result = substring;
                result_as_int = value;
            }
        }

        return result;
    }
};