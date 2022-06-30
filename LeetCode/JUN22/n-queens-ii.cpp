//
// Created by adeshchoudhar on 05/06/22.
//

class Solution {
public:
    int totalNQueens(int n) {
        int ans;
        vector <vector<bool>> board(n, vector<bool>(n, false));
        ans = totalNQueensUtil(board, 0, n);
        return ans;
    }

    int totalNQueensUtil(vector <vector<bool>> &board, int r, int n) {
        int cnt = 0;
        if (r == n) {
            cnt += 1;
            return cnt;
        }
        for (int c = 0; c < n; c++) {
            if (isValidNQueens(board, r, c, n)) {
                board[r][c] = true;
                cnt += totalNQueensUtil(board, r + 1, n);
                board[r][c] = false;
            }
        }
        return cnt;
    }

    bool isValidNQueens(vector <vector<bool>> &board, int r, int c, int n) {
        for (int i = 0; i < r; i++) {
            if (board[i][c]) {
                return false;
            }
        }
        for (int i = r - 1, j = c - 1; (i >= 0) && (j >= 0); i--, j--) {
            if (board[i][j]) {
                return false;
            }
        }
        for (int i = r - 1, j = c + 1; (i >= 0) && (j < n); i--, j++) {
            if (board[i][j]) {
                return false;
            }
        }
        return true;
    }
};
