//
// Created by adeshchoudhar on 27/8/22.
//

class Solution {
public:
    int maxSumSubmatrix(vector <vector<int>> &matrix, int k) {
        int ans = INT_MIN, row = matrix.size(), col = matrix[0].size();
        for (int l = 0; l < col; l++) {
            vector<int> sum(row);
            for (int r = l; r < col; r++) {
                for (int i = 0; i < row; i++) {
                    sum[i] += matrix[i][r];
                }
                set<int> s = {0};
                int cur = 0;
                for (int x: sum) {
                    cur += x;
                    auto it = s.lower_bound(cur - k);
                    if (it != s.end()) {
                        ans = max(ans, cur - *it);
                    }
                    s.insert(cur);
                }
            }
        }
        return ans;
    }
};
