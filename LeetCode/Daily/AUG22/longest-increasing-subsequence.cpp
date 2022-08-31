//
// Created by adeshchoudhar on 8/8/22.
//

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int ans, n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};
