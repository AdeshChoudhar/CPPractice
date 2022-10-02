//
// Created by adeshchoudhar on 16/9/22.
//

class Solution {
public:
    vector <vector<int>> dp;

    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        int ans;
        dp.resize(1001, vector<int>(1001, INT_MIN));
        ans = maximumScoreUtil(nums, multipliers, 0, 0);
        return ans;
    }

    int maximumScoreUtil(vector<int> &nums, vector<int> &multipliers, int l, int i) {
        int res = 0;
        if (i >= multipliers.size()) {
            return 0;
        }
        if (dp[l][i] == INT_MIN) {
            int r = nums.size() - 1 - (i - l);
            dp[l][i] = max(
                    nums[l] * multipliers[i] + maximumScoreUtil(nums, multipliers, l + 1, i + 1),
                    nums[r] * multipliers[i] + maximumScoreUtil(nums, multipliers, l, i + 1)
            );
        }
        res = dp[l][i];
        return res;
    }
};
