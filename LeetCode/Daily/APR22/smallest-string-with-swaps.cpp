//
// Created by adeshchoudhar on 27/04/22.
//

class Solution {
public:
    vector<int> ds;

    string smallestStringWithSwaps(string s, vector <vector<int>> &pairs) {
        string ans = s, tmp;
        ds.resize(s.size(), -1);
        vector <vector<int>> m(s.size());
        for (auto p: pairs) {
            int i = findParent(p[0]), j = findParent(p[1]);
            if (i != j) {
                ds[j] = i;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            m[findParent(i)].push_back(i);
        }
        for (auto x: m) {
            tmp = "";
            for (auto y: x) {
                tmp.push_back(s[y]);
            }
            sort(tmp.begin(), tmp.end());
            for (int i = 0, n = tmp.size(); i < n; i++) {
                ans[x[i]] = tmp[i];
            }
        }
        return ans;
    }

    int findParent(int i) {
        int parent;
        if (ds[i] < 0) {
            parent = i;
        } else {
            ds[i] = findParent(ds[i]);
            parent = ds[i];
        }
        return parent;
    }
};
