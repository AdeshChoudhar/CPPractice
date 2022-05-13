//
// Created by adeshchoudhar on 17/02/22.
//

class Solution {
public:
    vector <vector<int>> ans;
    vector<int> p;

    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        int i = 0;
        sort(candidates.begin(), candidates.end());
        combinationSumUtil(candidates, target, i);
        return ans;
    }

    void combinationSumUtil(vector<int> &candidates, int target, int i) {
        if (target == 0) {
            ans.push_back(p);
            return;
        }
        while (i < candidates.size() && (target - candidates[i]) >= 0) {
            p.push_back(candidates[i]);
            combinationSumUtil(candidates, target - candidates[i], i);
            i += 1;
            p.pop_back();
        }
    }
};
