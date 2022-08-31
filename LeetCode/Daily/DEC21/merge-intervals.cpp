//
// Created by adeshchoudhar on 24/12/21.
//

class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        vector <vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b) {
            return (a[0] < b[0]);
        });
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
