//
// Created by adeshchoudhar on 28/04/22.
//

class Solution {
public:
    int minimumEffortPath(vector <vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue < pair < int, int >, vector < pair < int, int >>, greater < pair < int, int>>> pq;
        vector <vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({0, 0});
        int dir[5] = {-1, 0, 1, 0, -1};
        int ans = -1;
        while (!pq.empty()) {
            pair<int, int> tp = pq.top();
            pq.pop();
            int x = tp.second / 100;
            int y = tp.second % 100;
            if (visited[x][y]) {
                continue;
            }
            visited[x][y] = true;
            if (x == (m - 1) && y == (n - 1)) {
                ans = tp.first;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                int npos = nx * 100 + ny;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                pq.push({max(tp.first, abs(heights[nx][ny] - heights[x][y])), npos});
            }
        }
        return ans;
    }
};
