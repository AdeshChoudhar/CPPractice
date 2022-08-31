//
// Created by adeshchoudhar on 1/8/22.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans;
        vector <vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        ans = dp[m - 1][n - 1];
        return ans;
    }
};
