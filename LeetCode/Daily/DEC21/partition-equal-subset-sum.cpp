//
// Created by adeshchoudhar on 12/12/21.
//

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if (sum % 2) {
            return false;
        }
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j > 0; j--) {
                if (j >= nums[i]) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        bool ans = dp[sum];
        return ans;
    }
};
