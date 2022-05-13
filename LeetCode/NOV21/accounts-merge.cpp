//
// Created by adeshchoudhar on 29/11/21.
//

class Solution {
public:
    vector <vector<string>> accountsMerge(vector <vector<string>> &accounts) {
        unordered_map<string, int> msi;
        unordered_map<int, vector<string>> miv;
        vector<int> ds(accounts.size(), 0);
        for (int i = 0; i < accounts.size(); i++) {
            ds[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                if (msi.find(accounts[i][j]) != msi.end()) {
                    ds[ds_find(ds, i)] = ds_find(ds, msi[accounts[i][j]]);
                } else {
                    msi[accounts[i][j]] = ds[i];
                }
            }
        }
        for (auto x: msi) {
            miv[ds_find(ds, x.second)].push_back(x.first);
        }
        vector <string> email;
        vector <vector<string>> ans;
        for (auto x: miv) {
            email = x.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[x.first][0]);
            ans.push_back(email);
        }
        return ans;
    }

    int ds_find(vector<int> &v, int i) {
        while (v[i] != i) {
            i = v[i];
        }
        return i;
    }
};
