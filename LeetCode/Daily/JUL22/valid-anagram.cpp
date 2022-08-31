//
// Created by adeshchoudhar on 28/7/22.
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        bool ans;
        unordered_map<char, int> um1, um2;
        for (char x: s) {
            um1[x] += 1;
        }
        for (char x: t) {
            um2[x] += 1;
        }
        ans = (um1 == um2);
        return ans;
    }
};
