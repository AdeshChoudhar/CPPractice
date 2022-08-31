//
// Created by adeshchoudhar on 05/03/22.
//

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        int n = 10001;
        vector<int> dp(n, 0);
        for (int num: nums) {
            dp[num] += num;
        }
        int took = 0, skip = 0, tmp_took, tmp_skip;
        for (int i = 0; i < n; i++) {
            tmp_took = skip + dp[i];
            tmp_skip = max(skip, took);
            took = tmp_took;
            skip = tmp_skip;
        }
        int ans = max(took, skip);
        return ans;
    }
};
