#include <vector>

class Solution {
public:
    int findSpecialInteger(const std::vector<int>& arr) {

        if (arr.empty()) {
            return -1;
        }

        const auto over25{ arr.size() / 4.0 };
        auto curr{ arr[0] };
        int count{};
        int result{ -1 };

        for (const auto value : arr) {
            if (value != curr) {
                count = 0;
            }

            ++count;
            curr = value;
            
            if (count > over25) {
                result = curr;
                break;
            }
        }

        return result;
    }
};