//
// Created by adeshchoudhar on 30/9/22.
//

class Solution {
public:
    vector <vector<int>> getSkyline(vector <vector<int>> &buildings) {
        vector <vector<int>> ans;
        vector <pair<int, int>> v;
        for (vector<int> building: buildings) {
            v.push_back(make_pair(building[0], building[2]));
            v.push_back(make_pair(building[1], -1 * building[2]));
        }
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        multiset<int, greater<int>> ms;
        ms.insert(0);
        int mxm = 0, pre = 0;
        for (pair<int, int> x: v) {
            if (x.second >= 0) {
                ms.insert(x.second);
            } else {
                ms.erase(ms.find(abs(x.second)));
            }
            int cur = *(ms.begin());
            if (cur != pre) {
                ans.push_back({x.first, cur});
                pre = cur;
            }
        }
        return ans;
    }
};
