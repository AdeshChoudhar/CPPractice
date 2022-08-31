//
// Created by adeshchoudhar on 16/8/22.
//

class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        unordered_map<char, int> um;
        for (char x: s) {
            um[x] += 1;
        }
        for (int i = 0, n = s.length(); (i < n) && (ans == -1); i++) {
            if (um[s[i]] == 1) {
                ans = i;
            }
        }
        return ans;
    }
};
