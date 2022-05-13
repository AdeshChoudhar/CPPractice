//
// Created by adeshchoudhar on 11/11/21.
//

class Solution {
public:
    int minStartValue(vector<int> &nums) {
        int pre = 0, ans = INT_MAX;
        for (auto num: nums) {
            pre += num;
            ans = min(ans, pre);
        }
        ans = max(1, -1 * (ans - 1));
        return ans;
    }
};
