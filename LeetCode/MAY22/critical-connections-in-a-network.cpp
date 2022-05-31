//
// Created by adeshchoudhar on 18/05/22.
//

class Solution {
public:
    vector <vector<int>> ans;
    unordered_map<int, vector<int>> graph;
    vector<int> ids;
    vector<int> lls;
    int id;

    vector <vector<int>> criticalConnections(int n, vector <vector<int>> &connections) {
        id = 1;
        ids.resize(n, 0);
        lls.resize(n, 0);
        for (auto connection: connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        criticalConnectionsUtil(0, -1);
        return ans;
    }

    void criticalConnectionsUtil(int current, int previous) {
        ids[current] = id;
        lls[current] = id;
        id += 1;
        for (auto x: graph[current]) {
            if (ids[x] == 0) {
                criticalConnectionsUtil(x, current);
                lls[current] = min(lls[current], lls[x]);
            } else if (x != previous) {
                lls[current] = min(lls[current], ids[x]);
            }
            if (lls[x] > ids[current]) {
                ans.push_back({current, x});
            }
        }
    }
};
