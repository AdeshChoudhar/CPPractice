//
// Created by adeshchoudhar on 04/05/22.
//

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        int ans = 0;
        unordered_map<int, int> um;
        for (int num: nums) {
            if (um[k - num] > 0) {
                um[k - num] -= 1;
                ans += 1;
            } else {
                um[num] += 1;
            }
        }
        return ans;
    }
};
