//
// Created by adeshchoudhar on 16/06/22.
//

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int l = 0, r = 0, n = s.length();
        vector <vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; (j + i) < n; j++) {
                if ((i < 2) || dp[j + 1][j + i - 1]) {
                    dp[j][j + i] = (s[j] == s[j + i]);
                }
                if (dp[j][j + i] && (i > (r - l))) {
                    l = j;
                    r = j + i;
                }
            }
        }
        ans = s.substr(l, r - l + 1);
        return ans;
    }
};
