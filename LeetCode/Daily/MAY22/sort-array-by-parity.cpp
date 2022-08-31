//
// Created by adeshchoudhar on 02/05/22.
//

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] & 1) {
                swap(nums[i], nums[j]);
                j -= 1;
            } else {
                i += 1;
            }
        }
        return nums;
    }
};
