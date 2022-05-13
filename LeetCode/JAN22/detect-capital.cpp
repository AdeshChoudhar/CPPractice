//
// Created by adeshchoudhar on 24/01/22.
//

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag1 = true, flag2 = true, flag3 = true;
        for (int i = 0, n = word.length(); i < n; i++) {
            if (!('A' <= word[i] && word[i] <= 'Z')) {
                flag1 = false;
            } else if (!('a' <= word[i] && word[i] <= 'z')) {
                flag2 = false;
                if (i != 0) {
                    flag3 = false;
                }
            }
        }
        bool ans = flag1 || flag2 || flag3;
        return ans;
    }
};
