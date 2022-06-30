//
// Created by adeshchoudhar on 30/06/22.
//

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int ans = 0, med;
        sort(nums.begin(), nums.end());
        med = nums[nums.size() / 2];
        for (int num: nums) {
            ans += abs(num - med);
        }
        return ans;
    }
};
