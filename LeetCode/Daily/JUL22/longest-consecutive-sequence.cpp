//
// Created by adeshchoudhar on 5/7/22.
//

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int ans = 0, sum;
        unordered_map<int, int> um;
        for (int num: nums) {
            if (um[num] == 0) {
                sum = 1 + um[num - 1] + um[num + 1];
                um[num] = um[num - um[num - 1]] = um[num + um[num + 1]] = sum;
                ans = max(ans, um[num]);
            }
        }
        return ans;
    }
};
