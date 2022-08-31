//
// Created by adeshchoudhar on 25/7/22.
//

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans(2, -1);
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] < target) {
                l += 1;
            } else if (nums[m] > target) {
                r -= 1;
            } else {
                ans.assign(2, m);
                break;
            }
        }
        if (ans[0] != -1) {
            while ((ans[0] > 0) && (nums[ans[0] - 1] == target)) {
                ans[0] -= 1;
            }
            while ((ans[1] < (nums.size() - 1)) && (nums[ans[1] + 1] == target)) {
                ans[1] += 1;
            }
        }
        return ans;
    }
};
