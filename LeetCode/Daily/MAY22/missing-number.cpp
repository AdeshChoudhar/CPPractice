//
// Created by adeshchoudhar on 28/05/22.
//

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int ans, n = nums.size(), sum = 0;
        for (int num: nums) {
            sum += num;
        }
        ans = (n * (n + 1)) / 2 - sum;
        return ans;
    }
};
