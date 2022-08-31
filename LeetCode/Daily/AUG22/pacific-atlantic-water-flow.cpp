//
// Created by adeshchoudhar on 31/8/22.
//

class Solution {
public:
    vector <vector<bool>> pac;
    vector <vector<bool>> atl;

    vector <vector<int>> pacificAtlantic(vector <vector<int>> &heights) {
        vector <vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        pac.resize(m, vector<bool>(n, false));
        atl.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pacificAtlanticUtil(heights, pac, i, 0, INT_MIN);
            pacificAtlanticUtil(heights, atl, i, n - 1, INT_MIN);
        }
        for (int i = 0; i < n; i++) {
            pacificAtlanticUtil(heights, pac, 0, i, INT_MIN);
            pacificAtlanticUtil(heights, atl, m - 1, i, INT_MIN);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void pacificAtlanticUtil(vector <vector<int>> &heights, vector <vector<bool>> &vis, int i, int j, int h) {
        int m = heights.size(), n = heights[0].size();
        if ((i < 0) || (i >= m) || (j < 0) || (j >= n) || vis[i][j] || heights[i][j] < h) {
            return;
        }
        vis[i][j] = true;
        pacificAtlanticUtil(heights, vis, i, j - 1, heights[i][j]);
        pacificAtlanticUtil(heights, vis, i - 1, j, heights[i][j]);
        pacificAtlanticUtil(heights, vis, i, j + 1, heights[i][j]);
        pacificAtlanticUtil(heights, vis, i + 1, j, heights[i][j]);
    }
};
