//
// Created by adeshchoudhar on 15/9/22.
//

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        vector<int> ans;
        int n = changed.size();
        if ((n & 1) != 0) {
            return ans;
        }
        unordered_map<int, int> um;
        for (int x: changed) {
            um[x] += 1;
        }
        bool flag = true;
        sort(changed.begin(), changed.end());
        for (int x: changed) {
            if (um[x] == 0) {
                continue;
            }
            if (um[x * 2] == 0) {
                flag = false;
                break;
            }
            ans.push_back(x);
            um[x] -= 1;
            um[x * 2] -= 1;
        }
        if (!flag) {
            ans.clear();
        }
        return ans;
    }
};
