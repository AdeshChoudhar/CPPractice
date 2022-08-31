//
// Created by adeshchoudhar on 26/02/22.
//

class Tuple {
public:
    int node;
    int mask;
    int cost;

    Tuple(int node, int mask, int cost) {
        this->node = node;
        this->mask = mask;
        this->cost = cost;
    }
};

class Solution {
public:
    int shortestPathLength(vector <vector<int>> &graph) {
        int n = graph.size();
        int d = (1 << n) - 1;
        queue <Tuple> q;
        set <pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            int m = (1 << i);
            Tuple tuple(i, m, 1);
            q.push(tuple);
            s.insert(make_pair(i, m));
        }
        int ans = -1;
        while (!q.empty()) {
            Tuple current = q.front();
            q.pop();
            if (current.mask == d) {
                ans = current.cost - 1;
                break;
            }
            for (auto x: graph[current.node]) {
                int t = current.mask;
                t |= (1 << x);
                Tuple tuple(x, t, current.cost + 1);
                if (s.find(make_pair(x, t)) == s.end()) {
                    s.insert(make_pair(x, t));
                    q.push(tuple);
                }
            }
        }
        return ans;
    }
};
