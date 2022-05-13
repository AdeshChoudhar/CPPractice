//
// Created by adeshchoudhar on 21/02/22.
//

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> um;
        for (int num: nums) {
            um[num] += 1;
        }
        int ans, n = nums.size();
        for (auto x: um) {
            if (x.second > (int) floor(n / 2)) {
                ans = x.first;
                break;
            }
        }
        return ans;
    }
};