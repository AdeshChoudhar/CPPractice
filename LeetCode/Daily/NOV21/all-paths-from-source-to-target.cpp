//
// Created by adeshchoudhar on 28/11/21.
//

class Solution {
public:
    vector <vector<int>> ans;
    vector<int> path;

    vector <vector<int>> allPathsSourceTarget(vector <vector<int>> &graph) {
        ans.clear();
        path.clear();
        dfs(graph, 0);
        return ans;
    }

    void dfs(vector <vector<int>> &graph, int src) {
        path.push_back(src);
        if (src == (graph.size() - 1)) {
            ans.push_back(path);
        } else {
            for (int x: graph[src]) {
                dfs(graph, x);
            }
        }
        path.pop_back();
    }
};
