//
// Created by adeshchoudhar on 13/12/21.
//

class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int cnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] == s[i]) {
                cnt += 1;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
