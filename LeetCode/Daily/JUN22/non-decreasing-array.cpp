//
// Created by adeshchoudhar on 25/06/22.
//

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        bool ans = true;
        for (int i = 1, n = nums.size(), p = nums[0], cnt = 0; i < n; i++) {
            if (nums[i] < p) {
                if (cnt == 1) {
                    ans = false;
                    break;
                }
                cnt += 1;
                if (((i - 2) >= 0) && (nums[i - 2] > nums[i])) {
                    continue;
                }
            }
            p = nums[i];
        }
        return ans;
    }
};
