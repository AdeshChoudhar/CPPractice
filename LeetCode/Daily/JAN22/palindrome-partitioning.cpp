//
// Created by adeshchoudhar on 05/01/22.
//

class Solution {
public:
    vector <vector<string>> partition(string s) {
        vector <vector<string>> ans;
        vector <string> path;
        int ind = 0;
        dfs(ind, s, path, ans);
        return ans;
    }

    void dfs(int ind, string &s, vector <string> &path, vector <vector<string>> &res) {
        if (ind == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = ind; i < s.size(); ++i) {
            if (isPalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i - ind + 1));
                dfs(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
