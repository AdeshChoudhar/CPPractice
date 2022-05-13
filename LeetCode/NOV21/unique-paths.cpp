//
// Created by adeshchoudhar on 17/11/21.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
        int ans = dp[m][n];
        return ans;
    }
};
