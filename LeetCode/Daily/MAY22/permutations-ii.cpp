//
// Created by adeshchoudhar on 12/05/22.
//

class Solution {
public:
    vector <vector<int>> permuteUnique(vector<int> &nums) {
        vector <vector<int>> ans;
        vector<int> tmp(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        } while (nums != tmp);
        return ans;
    }
};
