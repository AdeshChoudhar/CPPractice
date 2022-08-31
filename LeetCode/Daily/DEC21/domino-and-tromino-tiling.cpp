//
// Created by adeshchoudhar on 10/12/21.
//

class Solution {
public:
    int numTilings(int n) {
        int mod = (int) (1e9 + 7);
        vector<long long> dp(1001, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if (n >= 4) {
            for (int i = 4; i < n + 1; i++) {
                dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
            }
        }
        int ans = dp[n];
        return ans;
    }
};
