//
// Created by adeshchoudhar on 02/03/22.
//

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, m = s.length();
        for (int i = 0, n = t.length(); i < n and j < m; i++) {
            if (s[j] == t[i]) {
                j += 1;
            }
        }
        bool ans = (j == m);
        return ans;
    }
};
