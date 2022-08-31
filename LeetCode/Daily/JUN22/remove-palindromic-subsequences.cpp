//
// Created by adeshchoudhar on 08/06/22.
//

class Solution {
public:
    int removePalindromeSub(string s) {
        int ans;
        bool flag = true;
        for (int i = 0, n = s.length(); (i < (n / 2)) && flag; i++) {
            if (s[i] != s[n - 1 - i]) {
                flag = false;
            }
        }
        ans = flag ? 1 : 2;
        return ans;
    }
};
