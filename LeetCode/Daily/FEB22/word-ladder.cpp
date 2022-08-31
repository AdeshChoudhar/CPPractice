//
// Created by adeshchoudhar on 12/02/22.
//

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector <string> &wordList) {
        unordered_set <string> us(wordList.begin(), wordList.end());
        if (us.find(endWord) == us.end()) {
            return 0;
        }
        queue <string> q;
        q.push(beginWord);
        int ans = 1;
        string current;
        char c;
        while (!q.empty()) {
            for (int i = 0, n = q.size(); i < n; i++) {
                current = q.front();
                q.pop();
                if (current == endWord) {
                    return ans;
                }
                us.erase(current);
                for (int j = 0, m = current.size(); j < m; j++) {
                    c = current[j];
                    for (int k = 0; k < 26; k++) {
                        current[j] = 'a' + k;
                        if (us.find(current) != us.end()) {
                            q.push(current);
                        }
                    }
                    current[j] = c;
                }
            }
            ans += 1;
        }
        return 0;
    }
};
