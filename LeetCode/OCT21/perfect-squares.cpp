//
// Created by adeshchoudhar on 14/10/21.
//

class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        if (n == 0) {
            return 0;
        } else if (fmod(sqrt(n), 1.0) == 0.0) {
            return 1;
        } else if (dp[n] != -1) {
            return dp[n];
        }

        int mini = n;
        for (int i = 1; i * i <= n; i++) {
            mini = min(mini, solve(n - i * i) + 1);
        }
        dp[n] = mini;
        return mini;
    }

    int numSquares(int n) {
        dp.resize(10001, -1);
        int ans = solve(n);
        return ans;
    }
};
