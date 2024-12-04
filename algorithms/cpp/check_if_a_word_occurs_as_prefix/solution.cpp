class Solution {
public:
    int isPrefixOfWord(const std::string& sentence, const std::string& searchWord) {
        std::stringstream ss(sentence);
        std::string word;
        int index{};
        while (std::getline(ss, word, ' ')) {
            ++index;
            if (word.size() < searchWord.size()) {
                continue;
            }
            const auto substr{ word.substr(0, searchWord.size()) };
            if (substr == searchWord) {
                return index;
            }
        }
        return -1;
    }
};
