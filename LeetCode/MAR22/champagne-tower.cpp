//
// Created by adeshchoudhar on 04/03/22.
//

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(101, 0.0);
        dp[0] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = i; j >= 0; j--) {
                dp[j + 1] += dp[j] = max(0.0, (dp[j] - 1) / 2);
            }
        }
        double ans = min(1.0, dp[query_glass]);
        return ans;
    }
};
