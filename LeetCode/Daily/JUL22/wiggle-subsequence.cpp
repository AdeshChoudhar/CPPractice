//
// Created by adeshchoudhar on 3/7/22.
//

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int ans, n = nums.size();
        vector<int> u(n, 1), d(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                d[i] = 1 + u[i - 1];
                u[i] = u[i - 1];
            } else if (nums[i] > nums[i - 1]) {
                u[i] = 1 + d[i - 1];
                d[i] = d[i - 1];
            } else {
                u[i] = u[i - 1];
                d[i] = d[i - 1];
            }
        }
        ans = max(u[n - 1], d[n - 1]);
        return ans;
    }
};
