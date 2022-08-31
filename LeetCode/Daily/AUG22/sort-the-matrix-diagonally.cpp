//
// Created by adeshchoudhar on 28/8/22.
//

class Solution {
public:
    vector <vector<int>> diagonalSort(vector <vector<int>> &mat) {
        vector <vector<int>> ans;
        int m = mat.size(), n = mat[0].size();
        unordered_map < int, priority_queue < int, vector < int >, greater < int>>> um;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                um[i - j].push(mat[i][j]);
            }
        }
        ans.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = um[i - j].top();
                um[i - j].pop();
            }
        }
        return ans;
    }
};
