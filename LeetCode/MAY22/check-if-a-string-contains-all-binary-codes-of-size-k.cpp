//
// Created by adeshchoudhar on 31/05/22.
//

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        bool ans;
        set<string> dss;
        for (int i = 0, n = s.size(); i <= (n - k); i++) {
            dss.insert(s.substr(i, k));
        }
        ans = (dss.size() == pow(2, k));
        return ans;
    }
};
