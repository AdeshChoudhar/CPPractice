//
// Created by adeshchoudhar on 27/11/21.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> ans(nums.size(), 1);
        int product_left = 1, product_right = 1;
        for (int i = 0, n = nums.size(); i < n; i++) {
            ans[i] *= product_left;
            product_left *= nums[i];
            ans[n - 1 - i] *= product_right;
            product_right *= nums[n - 1 - i];
        }
        return ans;
    }
};
