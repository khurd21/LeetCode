#include <vector>
#include <string>

// This is O(n + m) Time and Space (n and m are length of all of the strings in the array combined)

namespace {

    template <typename T>
    T sumAsT(const std::vector<T>& container) {
        T result{};
        for (const auto& element : container) {
            result += element;
        }
        return result;
    }

}

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        return sumAsT(word1) == sumAsT(word2);
    }
};

// Trivial Question - this is O(n + m) Time and O(1) Space

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        int s1{};
        int s2{};
        int v1{};
        int v2{};

        while (word1.size() > v1 && word2.size() > v2 ) {
            
            if (word1[v1][s1] != word2[v2][s2]) {
                return false;
            }

            ++s1;
            ++s2;
            if (word1[v1].size() <= s1) {
                s1 = 0;
                ++v1;
            }
            if (word2[v2].size() <= s2) {
                s2 = 0;
                ++v2;
            }
        }

        return !(word1.size() > v1 || word2.size() > v2);
    }
};