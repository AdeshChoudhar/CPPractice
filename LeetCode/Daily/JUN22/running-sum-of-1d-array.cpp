//
// Created by adeshchoudhar on 01/06/22.
//

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> ans(nums.size(), 0);
        ans[0] = nums[0];
        for (int i = 1, n = nums.size(); i < n; i++) {
            ans[i] = ans[i - 1] + nums[i];
        }
        return ans;
    }
};