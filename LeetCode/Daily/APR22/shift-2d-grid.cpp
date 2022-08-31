//
// Created by adeshchoudhar on 11/04/22.
//

class Solution {
public:
    vector <vector<int>> shiftGrid(vector <vector<int>> &grid, int k) {
        deque<int> dq;
        for (vector<int> row: grid) {
            for (int r: row) {
                dq.push_back(r);
            }
        }
        k %= dq.size();
        for (int i = 0; i < k; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        for (int i = 0, n = grid.size(); i < n; i++) {
            for (int j = 0, m = grid[0].size(); j < m; j++) {
                grid[i][j] = dq.front();
                dq.pop_front();
            }
        }
        return grid;
    }
};
