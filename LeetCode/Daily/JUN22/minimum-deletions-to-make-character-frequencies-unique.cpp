//
// Created by adeshchoudhar on 28/06/22.
//

class Solution {
public:
    int minDeletions(string s) {
        int ans = 0, n = 26;
        vector<int> v(n);
        for (char x: s) {
            v[x - 'a'] += 1;
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 1; i < n; i++) {
            ans += max(0, v[i] - max(0, v[i - 1] - 1));
            v[i] = min(v[i], max(0, v[i - 1] - 1));
        }
        return ans;
    }
};
