//
// Created by adeshchoudhar on 11/06/22.
//

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int ans = INT_MIN, sum = -x, tmp = 0, j = 0;
        for (int num: nums) {
            sum += num;
        }
        if (sum < 0) {
            ans = -1;
        } else if (sum == 0) {
            ans = nums.size();
        } else {
            for (int i = 0, n = nums.size(); i < n; i++) {
                if (tmp < sum) {
                    tmp += nums[i];
                }
                while (tmp >= sum) {
                    if (tmp == sum) {
                        ans = max(ans, i - j + 1);
                    }
                    tmp -= nums[j];
                    j += 1;
                }
            }
            ans = (ans != INT_MIN) ? nums.size() - ans : -1;
        }
        return ans;
    }
};
