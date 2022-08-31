//
// Created by adeshchoudhar on 10/06/22.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, j = -1;
        vector<int> v(255, -1);
        for (int i = 0, n = s.length(); i < n; i++) {
            if (v[s[i]] > j) {
                j = v[s[i]];
            }
            v[s[i]] = i;
            ans = max(ans, i - j);
        }
        return ans;
    }
};
