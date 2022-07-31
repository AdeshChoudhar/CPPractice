//
// Created by adeshchoudhar on 23/7/22.
//

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> ans(nums.size(), 0);
        vector <pair<int, int>> dp;
        for (int i = 0, n = nums.size(); i < n; i++) {
            dp.push_back(make_pair(nums[i], i));
        }
        countSmallerUtil(dp.begin(), dp.end(), ans);
        return ans;
    }

    void countSmallerUtil(vector<pair < int, int>>

    ::
    iterator l, vector<pair < int, int>>
    ::
    iterator r, vector<int>
    &res) {
        if ((r - l) <= 1) {
            return;
        }
        vector < pair < int, int >> ::iterator
        m = l + (r - l) / 2;
        countSmallerUtil(l, m, res);
        countSmallerUtil(m, r, res);
        for (vector < pair < int, int >> ::iterator i = l, j = m; i < m;
        i++) {
            while ((j < r) && ((*i).first > (*j).first)) {
                j += 1;
            }
            res[(*i).second] += (j - m);
        }
        inplace_merge(l, m, r);
    }
};
