//
// Created by adeshchoudhar on 9/7/22.
//

class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        int ans, n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            if (dq.front() < (i - k)) {
                dq.pop_front();
            }
            dp[i] = nums[i] + dp[dq.front()];
            while (!dq.empty() && (dp[dq.back()] <= dp[i])) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans = dp[n - 1];
        return ans;
    }
};
