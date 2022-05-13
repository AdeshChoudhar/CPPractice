//
// Created by adeshchoudhar on 04/02/22.
//

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int ans = 0, sum = 0;
        unordered_map<int, int> um;
        um.insert(make_pair(0, -1));
        for (int i = 0, n = nums.size(); i < n; i++) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (um.find(sum) != um.end()) {
                ans = max(ans, i - um[sum]);
            } else {
                um[sum] = i;
            }
        }
        return ans;
    }
};
