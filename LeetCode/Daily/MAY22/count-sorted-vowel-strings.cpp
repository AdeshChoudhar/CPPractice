//
// Created by adeshchoudhar on 11/05/22.
//

class Solution {
public:
    int countVowelStrings(int n) {
        int ans, a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 0; k < (n - 1); k++) {
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
            u = u;
        }
        ans = a + e + i + o + u;
        return ans;
    }
};
