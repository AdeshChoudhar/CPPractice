//
// Created by adeshchoudhar on 10/7/22.
//

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int ans, n = cost.size();
        vector<int> dp(cost.begin(), cost.end());
        for (int i = 2; i < n; i++) {
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        ans = min(dp[n - 1], dp[n - 2]);
        return ans;
    }
};
