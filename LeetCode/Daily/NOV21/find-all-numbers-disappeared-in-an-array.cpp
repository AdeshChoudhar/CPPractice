//
// Created by adeshchoudhar on 18/11/21.
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int size = nums.size(), tmp;
        for (int i = 0; i < size; i++) {
            tmp = abs(nums[i]) - 1;
            if (nums[tmp] > 0) {
                nums[tmp] = -nums[tmp];
            }
        }

        vector<int> ans;
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
