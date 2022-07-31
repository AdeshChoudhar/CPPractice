//
// Created by adeshchoudhar on 30/7/22.
//

class Solution {
public:
    vector <string> wordSubsets(vector <string> &words1, vector <string> &words2) {
        vector <string> ans;
        vector<int> v(26, 0);
        for (string word: words2) {
            vector<int> t(26, 0);
            for (char x: word) {
                t[x - 'a'] += 1;
            }
            for (int i = 0; i < 26; i++) {
                v[i] = max(v[i], t[i]);
            }
        }
        for (string word: words1) {
            vector<int> t(26, 0);
            for (char x: word) {
                t[x - 'a'] += 1;
            }
            bool flag = true;
            for (int i = 0; flag && (i < 26); i++) {
                if (v[i] > t[i]) {
                    flag = false;
                }
            }
            if (flag) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
