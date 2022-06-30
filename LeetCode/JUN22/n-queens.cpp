//
// Created by adeshchoudhar on 04/06/22.
//

class Solution {
public:
    vector <vector<string>> ans;
    vector <string> nQueens;

    vector <vector<string>> solveNQueens(int n) {
        ans.clear();
        nQueens.resize(n, string(n, '.'));
        solveNQueensUtil(0, n);
        return ans;
    }

    void solveNQueensUtil(int r, int n) {
        if (r == n) {
            ans.push_back(nQueens);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (isValidNQueens(r, c, n)) {
                nQueens[r][c] = 'Q';
                solveNQueensUtil(r + 1, n);
                nQueens[r][c] = '.';
            }
        }
    }

    bool isValidNQueens(int r, int c, int n) {
        for (int i = 0; i < r; i++) {
            if (nQueens[i][c] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c - 1; (i >= 0) && (j >= 0); i--, j--) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c + 1; (i >= 0) && (j < n); i--, j++) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
