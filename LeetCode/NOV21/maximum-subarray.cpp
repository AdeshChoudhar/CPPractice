//
// Created by adeshchoudhar on 25/11/21.
//

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int tmp = nums[0], ans = nums[0];
        for (int i = 1, n = nums.size(); i < n; ++i) {
            tmp = max(tmp + nums[i], nums[i]);
            ans = max(ans, tmp);
        }
        return ans;
    }
};
