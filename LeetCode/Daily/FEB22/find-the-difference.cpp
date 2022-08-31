//
// Created by adeshchoudhar on 07/02/22.
//

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        for (char x: s) {
            v[(int) (x - 'a')] += 1;
        }
        for (char x: t) {
            v[(int) (x - 'a')] -= 1;
        }
        char ans;
        for (int i = 0; i < 26; i++) {
            if (v[i]) {
                ans = (char) ('a' + i);
                break;
            }
        }
        return ans;
    }
};
