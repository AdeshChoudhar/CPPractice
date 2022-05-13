//
// Created by adeshchoudhar on 10/04/22.
//

class Solution {
public:
    int calPoints(vector <string> &ops) {
        int ans = 0, i = -1;
        vector<int> v;
        for (string op: ops) {
            if (op == "+") {
                v.push_back(v[i] + v[i - 1]);
                i += 1;
            } else if (op == "D") {
                v.push_back(2 * v[i]);
                i += 1;
            } else if (op == "C") {
                v.pop_back();
                i -= 1;
            } else {
                v.push_back(stoi(op));
                i += 1;
            }
        }
        for (int x: v) {
            ans += x;
        }
        return ans;
    }
};
