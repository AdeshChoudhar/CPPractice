//
// Created by adeshchoudhar on 16/7/22.
//

class Solution {
public:
    int mod = (int) (1e9 + 7);
    vector <vector<vector < int>>>
    dp;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans;
        dp.resize(m, vector < vector < int >> (n, vector<int>(maxMove, -1)));
        ans = findPathsUtil(m, n, maxMove, startRow, startColumn, 0);
        return ans;
    }

    int findPathsUtil(int m, int n, int maxMove, int i, int j, int move) {
        int res;
        if ((i < 0) || (i >= m) || (j < 0) || (j >= n)) {
            res = 1;
        } else if (move == maxMove) {
            res = 0;
        } else if (dp[i][j][move] != -1) {
            res = dp[i][j][move] % mod;
        } else {
            res = 0;
            res = (res + findPathsUtil(m, n, maxMove, i, j - 1, move + 1)) % mod;
            res = (res + findPathsUtil(m, n, maxMove, i - 1, j, move + 1)) % mod;
            res = (res + findPathsUtil(m, n, maxMove, i, j + 1, move + 1)) % mod;
            res = (res + findPathsUtil(m, n, maxMove, i + 1, j, move + 1)) % mod;
            dp[i][j][move] = res;
        }
        return res;
    }
};
