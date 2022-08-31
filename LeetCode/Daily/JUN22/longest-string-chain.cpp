//
// Created by adeshchoudhar on 15/06/22.
//

class Solution {
public:
    int longestStrChain(vector <string> &words) {
        int ans = 0;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });
        string s;
        unordered_map<string, int> dp;
        for (string word: words) {
            for (int i = 0, n = word.length(); i < n; i++) {
                s = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], 1 + dp[s]);
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};
