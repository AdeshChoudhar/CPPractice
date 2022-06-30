//
// Created by adeshchoudhar on 12/06/22.
//

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int ans = 0, sum = 0;
        unordered_set<int> us;
        for (int i = 0, j = 0, n = nums.size(); i < n; i++) {
            while (us.find(nums[i]) != us.end()) {
                us.erase(nums[j]);
                sum -= nums[j];
                j += 1;
            }
            us.insert(nums[i]);
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
