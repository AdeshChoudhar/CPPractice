//
// Created by adeshchoudhar on 03/10/21.
//

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        vector<int> jumps(n);
        jumps[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                jumps[i] = INT_MAX;
            } else if (nums[i] >= n - 1 - i) {
                jumps[i] = 1;
            } else {
                int mini = INT_MAX;
                for (int j = i + 1; j < n && j <= nums[i] + i; j++) {
                    mini = min(mini, jumps[j]);
                }
                if (mini != INT_MAX) {
                    jumps[i] = mini + 1;
                } else {
                    jumps[i] = mini;
                }
            }
        }

        return (jumps[0] != INT_MAX);
    }
};
