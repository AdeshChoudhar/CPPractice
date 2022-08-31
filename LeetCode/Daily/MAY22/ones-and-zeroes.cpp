//
// Created by adeshchoudhar on 23/05/22.
//

class Solution {
public:
    int findMaxForm(vector <string> &strs, int m, int n) {
        int ans, zeroes, ones;
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto str: strs) {
            zeroes = count(str.begin(), str.end(), '0');
            ones = str.size() - zeroes;
            for (int i = m; i >= zeroes; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeroes][j - ones]);
                }
            }
        }
        ans = dp[m][n];
        return ans;
    }
};
