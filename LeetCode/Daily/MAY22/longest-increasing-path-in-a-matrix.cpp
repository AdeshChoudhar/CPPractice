//
// Created by adeshchoudhar on 19/05/22.
//

class Solution {
public:
    int m, n;
    vector <vector<int>> dp;
    vector <pair<int, int>> dir = {{0,  1},
                                   {1,  0},
                                   {0,  -1},
                                   {-1, 0}};

    int longestIncreasingPath(vector <vector<int>> &matrix) {
        int ans = 0;
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, longestIncreasingPathUtil(matrix, i, j));
            }
        }
        return ans;
    }

    int longestIncreasingPathUtil(vector <vector<int>> &matrix, int i, int j) {
        int x, y;
        if (dp[i][j]) {
            return dp[i][j];
        }
        dp[i][j] = 1;
        for (auto d: dir) {
            x = i + d.first;
            y = j + d.second;
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + longestIncreasingPathUtil(matrix, x, y));
            }
        }
        return dp[i][j];
    }
};
