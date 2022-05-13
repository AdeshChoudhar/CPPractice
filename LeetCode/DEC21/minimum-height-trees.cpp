//
// Created by adeshchoudhar on 16/12/21.
//

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector <vector<int>> &edges) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        vector <unordered_set<int>> adj(n);
        for (auto e: edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        while (true) {
            vector<int> next_leaves;
            for (auto leaf: leaves) {
                for (auto neighbor: adj[leaf]) {
                    adj[neighbor].erase(leaf);
                    if (adj[neighbor].size() == 1) {
                        next_leaves.push_back(neighbor);
                    }
                }
            }
            if (next_leaves.empty()) {
                break;
            }
            leaves = next_leaves;
        }
        ans = leaves;
        return ans;
    }
};
