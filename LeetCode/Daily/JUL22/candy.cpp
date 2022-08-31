//
// Created by adeshchoudhar on 4/7/22.
//

class Solution {
public:
    int candy(vector<int> &ratings) {
        int ans, n = ratings.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                dp[i] = 1 + dp[i - 1];
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                dp[i - 1] = max(1 + dp[i], dp[i - 1]);
            }
        }
        ans = accumulate(dp.begin(), dp.end(), 0);
        return ans;
    }
};
