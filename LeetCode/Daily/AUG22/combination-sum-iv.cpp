//
// Created by adeshchoudhar on 5/8/22.
//

class Solution {
public:
    vector<int> dp;

    int combinationSum4(vector<int> &nums, int target) {
        int ans;
        dp.resize(10001, -1);
        ans = combinationSum4Util(nums, target, 0);
        return ans;
    }

    int combinationSum4Util(vector<int> &nums, int target, int sum) {
        if (dp[sum] != -1) {
            return dp[sum];
        }
        if (sum >= target) {
            return (int) (sum == target);
        }
        int res = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            res += combinationSum4Util(nums, target, sum + nums[i]);
        }
        dp[sum] = res;
        return dp[sum];
    }
};