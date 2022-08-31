//
// Created by adeshchoudhar on 02/02/22.
//

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) {
            return ans;
        }
        vector<int> vs(26, 0), vp(26, 0);
        for (int i = 0, n = p.length(); i < n; i++) {
            vs[s[i] - 'a'] += 1;
            vp[p[i] - 'a'] += 1;
        }
        if (vs == vp) {
            ans.push_back(0);
        }
        for (int i = p.length(), n = s.length(); i < n; i++) {
            vs[s[i] - 'a'] += 1;
            vs[s[i - p.length()] - 'a'] -= 1;
            if (vs == vp) {
                ans.push_back(i - p.length() + 1);
            }
        }
        return ans;
    }
};
