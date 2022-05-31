//
// Created by adeshchoudhar on 10/05/22.
//

class Solution {
public:
    vector <vector<int>> ans;
    vector<int> tmp;

    vector <vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        tmp.clear();
        combinationSum3Util(k, n);
        return ans;
    }

    void combinationSum3Util(int k, int n) {
        if (tmp.size() == k && n == 0) {
            ans.push_back(tmp);
            return;
        }
        for (int i = tmp.empty() ? 1 : tmp.back() + 1; i <= 9; i++) {
            if ((n - i) < 0) {
                break;
            }
            tmp.push_back(i);
            combinationSum3Util(k, n - i);
            tmp.pop_back();
        }
    }
};
