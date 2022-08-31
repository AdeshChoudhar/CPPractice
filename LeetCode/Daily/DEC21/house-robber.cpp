//
// Created by adeshchoudhar on 01/12/21.
//

class Solution {
public:
    int rob(vector<int> &nums) {
        int ans = 0, prev = 0, tmp;
        for (int num: nums) {
            tmp = ans;
            ans = max(ans, prev + num);
            prev = tmp;
        }
        return ans;
    }
};
