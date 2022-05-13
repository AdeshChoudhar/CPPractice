//
// Created by adeshchoudhar on 13/02/22.
//

class Solution {
public:
    vector <vector<int>> subsets(vector<int> &nums) {
        vector <vector<int>> ans = {{}};
        for (int num: nums) {
            for (int i = 0, n = ans.size(); i < n; i++) {
                ans.push_back(ans[i]);
                ans.back().push_back(num);
            }
        }
        return ans;
    }
};
