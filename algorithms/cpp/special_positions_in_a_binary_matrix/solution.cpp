#include <vector>
#include <algorithm>

class Solution {
public:
    int numSpecial(const std::vector<std::vector<int>>& mat) {
        int result{};
        for (const auto& row : mat) {
            if (std::count(row.begin(), row.end(), 1) != 1) {
                continue;
            }
            int count{};
            const int itr{ static_cast<int>(std::find(row.begin(), row.end(), 1) - row.begin()) };
            for (int j = 0; j < mat.size(); ++j) {
                count += mat[j][itr];
            }
            result += count == 1 ? 1 : 0;
        }

        return result;
    }
};