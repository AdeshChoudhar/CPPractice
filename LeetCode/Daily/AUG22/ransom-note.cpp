//
// Created by adeshchoudhar on 25/8/22.
//

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ans = true;
        unordered_map<char, int> um;
        for (char x: magazine) {
            um[x] += 1;
        }
        for (char x: ransomNote) {
            um[x] -= 1;
        }
        for (auto x: um) {
            if (x.second < 0) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
