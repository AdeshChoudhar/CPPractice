//
// Created by adeshchoudhar on 7/8/22.
//

class Solution {
public:
    int countVowelPermutation(int n) {
        int ans = 0, cnt = 5, mod = (int) (1e9 + 7);
        vector <vector<int>> dp(2, vector<int>(cnt, 0));
        for (int i = 0; i < cnt; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            dp[i & 1][0] = ((dp[!(i & 1)][1] + dp[!(i & 1)][2]) % mod + dp[!(i & 1)][4]) % mod;
            dp[i & 1][1] = (dp[!(i & 1)][0] + dp[!(i & 1)][2]) % mod;
            dp[i & 1][2] = (dp[!(i & 1)][1] + dp[!(i & 1)][3]) % mod;
            dp[i & 1][3] = dp[!(i & 1)][2];
            dp[i & 1][4] = (dp[!(i & 1)][2] + dp[!(i & 1)][3]) % mod;
        }
        for (int i = 0; i < cnt; i++) {
            ans = (ans + dp[!(n & 1)][i]) % mod;
        }
        return ans;
    }
};
