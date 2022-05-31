//
// Created by adeshchoudhar on 14/05/22.
//

class Solution {
public:
    int networkDelayTime(vector <vector<int>> &times, int n, int k) {
        int ans, u, m;
        map<pair<int, int>, int> graph;
        for (auto time: times) {
            graph[make_pair(time[0] - 1, time[1] - 1)] = time[2];
        }
        vector<int> dis(n, INT_MAX);
        vector<bool> vis(n, false);
        dis[k - 1] = 0;
        for (int i = 0; i < (n - 1); i++) {
            m = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!vis[j] && dis[j] < m) {
                    m = dis[j];
                    u = j;
                }
            }
            vis[u] = true;
            for (int v = 0; v < n; v++) {
                if (!vis[v] && (graph.find({u, v}) != graph.end())
                    && (dis[u] != INT_MAX) && (dis[u] + graph[{u, v}] < dis[v])) {
                    dis[v] = dis[u] + graph[{u, v}];
                }
            }
        }
        ans = *max_element(dis.begin(), dis.end());
        ans = (ans != INT_MAX) ? ans : -1;
        return ans;
    }
};
