//
// Created by adeshchoudhar on 15/02/22.
//

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int num: nums) {
            ans ^= num;
        }
        return ans;
    }
};
