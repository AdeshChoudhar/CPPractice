//
// Created by adeshchoudhar on 06/02/22.
//

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for (int num: nums) {
            if (i < 2 || num > nums[i - 2]) {
                nums[i] = num;
                i += 1;
            }
        }
        return i;
    }
};
