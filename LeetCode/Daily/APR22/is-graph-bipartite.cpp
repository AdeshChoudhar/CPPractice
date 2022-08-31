//
// Created by adeshchoudhar on 29/04/22.
//

class Solution {
public:
    vector<bool> visited, colour;

    bool isBipartite(vector <vector<int>> &graph) {
        bool ans = true;
        int n = graph.size();
        visited.resize(n);
        colour.resize(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && !isBipartiteUtil(graph, i, 0)) {
                ans = false;
                break;
            }
        }
        return ans;
    }

    bool isBipartiteUtil(vector <vector<int>> &graph, int i, bool c) {
        bool res = true;
        visited[i] = true;
        colour[i] = c;
        for (int neighbour: graph[i]) {
            if ((!visited[neighbour] && !isBipartiteUtil(graph, neighbour, !c)) || (colour[i] == colour[neighbour])) {
                res = false;
                break;
            }
        }
        return res;
    }
};
