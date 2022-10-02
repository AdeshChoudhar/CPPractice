//
// Created by adeshchoudhar on 27/9/22.
//

class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = dominoes;
        int l = 0, n = ans.size();
        for (int r = 0; r < n; r++) {
            if (ans[r] == '.') {
                continue;
            } else if ((ans[l] == ans[r]) || ((ans[l] == '.') && (ans[r] == 'L'))) {
                for (int i = l; i < r; i++) {
                    ans[i] = ans[r];
                }
            } else if ((ans[l] == 'R') && (ans[r] == 'L')) {
                int m = (r - l - 1) / 2;
                for (int i = 1; i <= m; i++) {
                    ans[r - i] = 'L';
                    ans[l + i] = 'R';
                }
            }
            l = r;
        }
        if (ans[l] == 'R') {
            for (int i = l; i < n; i++) {
                ans[i] = 'R';
            }
        }
        return ans;
    }
};
