//
// Created by adeshchoudhar on 29/7/22.
//

class Solution {
public:
    vector <string> findAndReplacePattern(vector <string> &words, string pattern) {
        vector <string> ans;
        for (string word: words) {
            bool flag = true;
            unordered_map<char, char> um1, um2;
            for (int i = 0, n = pattern.length(); flag && (i < n); i++) {
                if (um1.find(pattern[i]) == um1.end()) {
                    um1[pattern[i]] = word[i];
                } else {
                    if (um1[pattern[i]] != word[i]) {
                        flag = false;
                    }
                }
                if (um2.find(word[i]) == um2.end()) {
                    um2[word[i]] = pattern[i];
                } else {
                    if (um2[word[i]] != pattern[i]) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
