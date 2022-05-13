//
// Created by adeshchoudhar on 26/04/22.
//

class Solution {
public:
    vector<int> parents;

    int minCostConnectPoints(vector <vector<int>> &points) {
        int ans = 0, n = points.size();
        parents.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        priority_queue <vector<int>> pq;
        for (int i = 0; i < (n - 1); i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                pq.push({-1 * (abs(x1 - x2) + abs(y1 - y2)), i, j});
            }
        }
        vector<int> edge;
        int edges = 0, p1, p2;
        while (edges != (n - 1)) {
            edge = pq.top();
            int p1 = getParent(edge[1]);
            int p2 = getParent(edge[2]);
            if (p1 != p2) {
                ans += (-1 * edge[0]);
                parents[p1] = p2;
                edges += 1;
            }
            pq.pop();
        }
        return ans;
    }

    int getParent(int i) {
        if (parents[i] == i) {
            return i;
        }
        parents[i] = getParent(parents[parents[i]]);
        return parents[i];
    }
};
