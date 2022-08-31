//
// Created by adeshchoudhar on 25/05/22.
//

class Solution {
public:
    int maxEnvelopes(vector <vector<int>> &envelopes) {
        int ans, h, l;
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return (a[0] == b[0]) ? (b[1] < a[1]) : (a[0] < b[0]);
        });
        vector<int> dp;
        for (auto envelope: envelopes) {
            h = envelope[1];
            l = lower_bound(dp.begin(), dp.end(), h) - dp.begin();
            if (l == dp.size()) {
                dp.push_back(h);
            }
            dp[l] = h;
        }
        ans = dp.size();
        return ans;
    }
};
