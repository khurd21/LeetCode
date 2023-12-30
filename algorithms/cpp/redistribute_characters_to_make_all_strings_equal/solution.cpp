#include <vector>
#include <string>
#include <array>

class Solution {
public:
    bool makeEqual(const std::vector<std::string>& words) {

        const int size( words.size() );
        std::array<int, 26> counts{};

        for (const auto& word : words) {
            for (char letter : word) {
                const int index( letter - 'a' );
                counts[index] += 1;
            }
        }

        for (auto count : counts) {
            if (count % size != 0) {
                return false;
            }
        }

        return true;
    }
};