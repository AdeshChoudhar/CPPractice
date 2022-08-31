//
// Created by adeshchoudhar on 21/8/22.
//

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int total = 0, current = -1;
        while (current) {
            current = 0;
            for (int i = stamp.size(); i > 0; i--)
                for (int j = 0; j <= stamp.size() - i; j++) {
                    string mask = string(j, '*') + stamp.substr(j, i) + string(stamp.size() - i - j, '*');
                    int idx = target.find(mask);
                    while (idx != string::npos) {
                        ans.push_back(idx);
                        current += i;
                        fill(target.begin() + idx, target.begin() + idx + stamp.size(), '*');
                        idx = target.find(mask);
                    }
                }
            total += current;
        }
        reverse(ans.begin(), ans.end());
        if (total != target.size()) {
            ans.clear();
        }
        return ans;
    }
};
