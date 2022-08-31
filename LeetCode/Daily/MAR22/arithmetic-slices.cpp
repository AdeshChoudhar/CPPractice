//
// Created by adeshchoudhar on 03/03/22.
//

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int ans = 0;
        if (nums.size() < 3) {
            return ans;
        }
        int ind = 0, diff = 0, prev = nums[1] - nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            diff = nums[i + 1] - nums[i];
            if (diff == prev) {
                ind += 1;
            } else {
                prev = diff;
                ind = 0;
            }
            ans += ind;
        }
        return ans;
    }
};
