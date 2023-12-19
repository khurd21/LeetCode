#include <vector>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> result(A.size(), 0);
        std::vector<int> count(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            count[A[i] - 1] += 1;
            count[B[i] - 1] += 1;
            if (i > 0) {
                result[i] = result[i - 1];
            }
            if (count[A[i] - 1] == 2) {
                count[A[i] - 1] = -1;
                result[i] += 1;
            }
            if (count[B[i] - 1] == 2) {
                count[B[i] - 1] = -1;
                result[i] += 1;
            }
        }

        return result;
    }
};