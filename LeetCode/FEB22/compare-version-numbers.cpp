//
// Created by adeshchoudhar on 25/02/22.
//

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string tmp = "";
        for (char x: version1) {
            if (x == '.' && !tmp.empty()) {
                v1.push_back(stoi(tmp));
                tmp = "";
            } else {
                tmp.push_back(x);
            }
        }
        if (!tmp.empty()) {
            v1.push_back(stoi(tmp));
        }
        tmp = "";
        for (char x: version2) {
            if (x == '.' && !tmp.empty()) {
                v2.push_back(stoi(tmp));
                tmp = "";
            } else {
                tmp.push_back(x);
            }
        }
        if (!tmp.empty()) {
            v2.push_back(stoi(tmp));
        }
        if (v1.size() < v2.size()) {
            for (int i = 0, n = v2.size() - v1.size(); i < n; i++) {
                v1.push_back(0);
            }
        }
        if (v1.size() > v2.size()) {
            for (int i = 0, n = v1.size() - v2.size(); i < n; i++) {
                v2.push_back(0);
            }
        }
        int ans = 0;
        for (int i = 0, n = v1.size(); i < n; i++) {
            if (v1[i] < v2[i]) {
                ans = -1;
                break;
            } else if (v1[i] > v2[i]) {
                ans = 1;
                break;
            }
        }
        return ans;
    }
};
