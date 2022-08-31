//
// Created by adeshchoudhar on 22/10/21.
//

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] += 1;
        }

        vector <pair<char, int>> v;
        for (auto i = mp.begin(); i != mp.end(); i++) {
            v.push_back(make_pair(i->first, i->second));
        }

        sort(v.begin(), v.end(), [](pair<char, int> &a, pair<char, int> &b) {
            return a.second > b.second;
        });

        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].second; j++) {
                ans += v[i].first;
            }
        }
        return ans;
    }
};
