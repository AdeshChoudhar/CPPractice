//
// Created by adeshchoudhar on 27/03/22.
//

class Solution {
public:
    vector<int> kWeakestRows(vector <vector<int>> &mat, int k) {
        vector<int> ans;
        set <pair<int, int>> s;
        for (int i = 0, n = mat.size(), tmp; i < n; i++) {
            tmp = 0;
            for (auto x: mat[i]) {
                if (x == 1) {
                    tmp += 1;
                }
            }
            s.insert(make_pair(tmp, i));
        }
        for (auto it = s.begin(); k > 0; it++, k--) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
