//
// Created by adeshchoudhar on 06/11/21.
//

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        long long int nums_xor = 0;
        for (auto num: nums) {
            nums_xor ^= num;
        }

        long long int set_bit = nums_xor & ~(nums_xor - 1);
        int first = 0, second = 0;
        for (auto num: nums) {
            if (num & set_bit) {
                first ^= num;
            } else {
                second ^= num;
            }
        }

        vector<int> ans = {first, second};
        return ans;
    }
};
