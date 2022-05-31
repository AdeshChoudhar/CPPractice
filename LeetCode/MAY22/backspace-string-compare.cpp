//
// Created by adeshchoudhar on 01/05/22.
//

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        bool ans;
        string S = "", T = "";
        for (char x: s) {
            if (x == '#') {
                if (!S.empty()) {
                    S.pop_back();
                }
            } else {
                S.push_back(x);
            }
        }
        for (char x: t) {
            if (x == '#') {
                if (!T.empty()) {
                    T.pop_back();
                }
            } else {
                T.push_back(x);
            }
        }
        ans = (S == T);
        return ans;
    }
};
