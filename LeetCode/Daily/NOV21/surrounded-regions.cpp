//
// Created by adeshchoudhar on 01/11/21.
//

class Solution {
public:
    void solve(vector <vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        if (m < 3 || n < 3) {
            return;
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector <vector<char>> &board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        board[row][col] = '.';
        vector <pair<int, int>> directions = {{1,  0},
                                              {-1, 0},
                                              {0,  1},
                                              {0,  -1}};
        for (auto xy: directions) {
            int r = row + xy.first;
            int c = col + xy.second;
            if (r >= 0 && r <= (m - 1) && c >= 0 && c <= (n - 1) && board[r][c] == 'O') {
                dfs(board, r, c);
            }
        }
    }
};
