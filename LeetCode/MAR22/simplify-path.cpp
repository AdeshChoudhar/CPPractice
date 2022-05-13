//
// Created by adeshchoudhar on 14/03/22.
//

class Solution {
public:
    string simplifyPath(string path) {
        string token;
        stringstream ss(path);
        vector <string> tokens;
        while (getline(ss, token, '/')) {
            if (token == "." || token == "") {
                continue;
            } else if (token == "..") {
                if (tokens.size() != 0) {
                    tokens.pop_back();
                }
            } else {
                tokens.push_back(token);
            }
        }
        string ans = "";
        if (tokens.size()) {
            for (int i = 0; i < tokens.size(); ++i) {
                ans += ("/" + tokens[i]);
            }
        } else {
            ans.push_back('/');
        }
        return ans;
    }
};
