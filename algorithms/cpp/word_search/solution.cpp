#include <vector>
#include <string>

namespace {

void search(auto& board, int i, int j, const auto& word, auto itr, auto& result) {
    if (itr == word.cend()) {
        result = true;
        return;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board.at(i).size()) {
        return;
    }
    if (board.at(i).at(j) == '*') {
        return;
    }
    const auto value{ board.at(i).at(j) };
    board.at(i).at(j) = '*';
    if (value == *itr) {
        ++itr;
        search(board, i + 1, j, word, itr, result);
        search(board, i - 1, j, word, itr, result);
        search(board, i, j + 1, word, itr, result);
        search(board, i, j - 1, word, itr, result);
    }
    board.at(i).at(j) = value;
}

}

class Solution {
public:
    bool exist(std::vector<std::vector<char>> board, const std::string& word) {
        for (int i{}; i < board.size(); ++i) {
            for (int j{}; j < board[i].size(); ++j) {
                if (board[i][j] == *word.begin()) {
                    bool result{};
                    search(board, i, j, word, word.cbegin(), result);
                    if (result) {
                        return true;
                    }
                }
            }
        }
        return {};
    }
};