//
// Created by adeshchoudhar on 20/7/22.
//

class Solution {
public:
    int numMatchingSubseq(string s, vector <string> &words) {
        int ans = 0, idx;
        vector <vector<int>> v(26, vector<int>());
        for (int i = 0, n = s.length(); i < n; i++) {
            v[s[i] - 'a'].push_back(i);
        }
        for (string word: words) {
            idx = -1;
            ans += 1;
            for (char x: word) {
                auto it = upper_bound(v[x - 'a'].begin(), v[x - 'a'].end(), idx);
                if (it == v[x - 'a'].end()) {
                    ans -= 1;
                    break;
                } else {
                    idx = *it;
                }
            }
        }
        return ans;
    }
};
