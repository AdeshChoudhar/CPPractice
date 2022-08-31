//
// Created by adeshchoudhar on 17/01/22.
//

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<int> v(26, 0);
        unordered_map<string, int> m;
        istringstream iss(s);
        string token;
        int i = 0, n = pattern.size();
        for (; iss >> token; i++) {
            if (i == n || v[pattern[i] - 'a'] != m[token]) {
                return false;
            }
            v[pattern[i] - 'a'] = i + 1;
            m[token] = i + 1;
        }
        return (i == n);
    }
};
