//
// Created by adeshchoudhar on 07/10/21.
//

class Solution {
public:
    bool exist(vector <vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector <vector<char>> &board, int i, int j, string word, int w) {
        if (w == word.size()) {
            return true;
        }

        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '.') {
            return false;
        }

        if (board[i][j] != word[w]) {
            return false;
        }

        char tmp = board[i][j];
        board[i][j] = '.';
        if (dfs(board, i - 1, j, word, w + 1)
            || dfs(board, i + 1, j, word, w + 1)
            || dfs(board, i, j - 1, word, w + 1)
            || dfs(board, i, j + 1, word, w + 1)) {
            return true;
        }

        board[i][j] = tmp;
        return false;
    }
};
