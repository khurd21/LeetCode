#include <unordered_set>
#include <string>
#include <vector>

class Solution {
public:
    std::string replaceWords(const std::vector<std::string>& dictionary, const std::string& sentence) {
        std::string result;
        std::unordered_set<std::string> words(dictionary.cbegin(), dictionary.cend());
        auto front{ sentence.cbegin() };
        auto back{ sentence.cbegin() + 1 };
        bool isFound{};
        while (back < sentence.cend()) {
            if (*back == ' ') {
                if (!isFound) {
                    result += std::string(front, back);
                    result += " ";
                }
                ++back;
                front = back;
                ++back;
                isFound = false;
                continue;
            }
            const std::string sub(front, back);
            if (!isFound && words.contains(sub)) {
                result += sub;
                result += " ";
                isFound = true;
            }
            else {
                ++back;
            }
        }
        if (!isFound) {
            result += std::string(front, back);
        }
        else {
            result.erase(result.cend() - 1);
        }
        return result;
    }
};