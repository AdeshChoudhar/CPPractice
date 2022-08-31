//
// Created by adeshchoudhar on 02/06/22.
//

class Solution {
public:
    vector <vector<int>> transpose(vector <vector<int>> &matrix) {
        vector <vector<int>> ans;
        int m = matrix.size(), n = matrix[0].size();
        ans.resize(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
