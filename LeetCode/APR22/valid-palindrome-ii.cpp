//
// Created by adeshchoudhar on 05/04/22.
//

class Solution {
public:
    bool validPalindrome(string s) {
        bool ans = validPalindromeUtil(s, 0, s.size() - 1, 0);
        return ans;
    }

    bool validPalindromeUtil(string s, int l, int r, int c) {
        if (c > 1) {
            return false;
        }
        while (l < r) {
            if (s[l] == s[r]) {
                l += 1;
                r -= 1;
            } else {
                return validPalindromeUtil(s, l + 1, r, c + 1) || validPalindromeUtil(s, l, r - 1, c + 1);
            }
        }
        return true;
    }
};
