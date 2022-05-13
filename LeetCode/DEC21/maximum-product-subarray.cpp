//
// Created by adeshchoudhar on 03/12/21.
//

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int ans = INT_MIN;
        int mini = 1, maxi = 1, tmp;
        for (int i = 0, n = nums.size(); i < n; i++) {
            tmp = mini;
            mini = min({nums[i], mini * nums[i], maxi * nums[i]});
            maxi = max({nums[i], tmp * nums[i], maxi * nums[i]});
            ans = max(ans, maxi);
        }
        return ans;
    }
};
