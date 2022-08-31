//
// Created by adeshchoudhar on 10/02/22.
//

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> um;
        um[0] = 1;
        for (int num: nums) {
            sum += num;
            if (um.find(sum - k) != um.end()) {
                ans += um[sum - k];
            }
            um[sum] += 1;
        }
        return ans;
    }
};
