//
// Created by adeshchoudhar on 21/03/22.
//

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> um;
        for (int i = 0, n = s.length(); i < n; i++) {
            um[s[i]] = i;
        }
        int maxi = 0, prev = -1;
        for (int i = 0, n = s.length(); i < n; i++) {
            maxi = max(maxi, um[s[i]]);
            if (maxi == i) {
                ans.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return ans;
    }
};
