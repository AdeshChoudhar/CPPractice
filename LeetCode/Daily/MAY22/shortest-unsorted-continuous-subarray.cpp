//
// Created by adeshchoudhar on 03/05/22.
//

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int ans, l = 0, r = 0, mini = INT_MAX, maxi = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            if (nums[i] != mini) {
                l = i;
            }
        }
        for (int i = 0, n = nums.size(); i < n; i++) {
            maxi = max(maxi, nums[i]);
            if (nums[i] != maxi) {
                r = i;
            }
        }
        ans = (l == r) ? 0 : r - l + 1;
        return ans;
    }
};
