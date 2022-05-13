//
// Created by adeshchoudhar on 01/01/22.
//

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int balloons[nums.size() + 2];
        int n = 0;
        balloons[n] = 1;
        n += 1;
        for (int x: nums) {
            if (x > 0) {
                balloons[n] = x;
                n += 1;
            }
        }
        balloons[n] = 1;
        n += 1;
        vector <vector<int>> dp(n, vector<int>(n, 0));
        for (int k = 2; k < n; k++) {
            for (int left = 0; left < n - k; left++) {
                int right = left + k;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right],
                                          balloons[left] * balloons[i] * balloons[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        int ans = dp[0][n - 1];
        return ans;
    }
};
