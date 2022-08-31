//
// Created by adeshchoudhar on 15/11/21.
//

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 1);
        vector<int> pi(nums.size(), -1);

        int ind = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j] == 0) && (dp[i] < (dp[j] + 1))) {
                    dp[i] = dp[j] + 1;
                    pi[i] = j;
                }
            }
            if (dp[i] > dp[ind]) {
                ind = i;
            }
        }

        vector<int> ans;
        while (ind >= 0) {
            ans.push_back(nums[ind]);
            ind = pi[ind];
        }
        return ans;
    }
};
