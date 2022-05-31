//
// Created by adeshchoudhar on 22/05/22.
//

class Solution {
public:
    int ans = 0;

    int countSubstrings(string s) {
        for (int i = 0, n = s.length(); i < n; i++) {
            countSubstringsUtil(s, i, i);
            countSubstringsUtil(s, i, i + 1);
        }
        return ans;
    }

    void countSubstringsUtil(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            ans += 1;
            l -= 1;
            r += 1;
        }
    }
};
