//
// Created by adeshchoudhar on 19/9/22.
//

class Solution {
public:
    vector <vector<string>> findDuplicate(vector <string> &paths) {
        vector <vector<string>> ans;
        unordered_map <string, vector<string>> um;
        for (string path: paths) {
            string s, dir;
            bool flag = true;
            stringstream ss(path);
            while (getline(ss, s, ' ')) {
                if (flag) {
                    dir = s;
                    flag = false;
                } else {
                    string file = s.substr(0, s.find('('));
                    string content = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                    um[content].push_back(dir + "/" + file);
                }
            }
        }
        for (auto x: um) {
            if (x.second.size() > 1) {
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};
