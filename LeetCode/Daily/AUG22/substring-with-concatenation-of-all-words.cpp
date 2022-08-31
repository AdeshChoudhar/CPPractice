//
// Created by adeshchoudhar on 13/8/22.
//

class Solution {
public:
    vector<int> findSubstring(string s, vector <string> &words) {
        vector<int> ans;
        unordered_map<string, int> um;
        for (string word: words) {
            um[word] += 1;
        }
        int n = words.size(), l = words[0].length();
        for (int i = 0; i < s.length() - n * l + 1; i++) {
            unordered_map<string, int> us;
            int j = 0;
            for (; j < n; j++) {
                string word = s.substr(i + j * l, l);
                if (um.find(word) != um.end()) {
                    us[word] += 1;
                    if (us[word] > um[word]) {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (j == n) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
