//
// Created by adeshchoudhar on 23/12/21.
//

class Solution {
public:
    vector<int> findOrder(int numCourses, vector <vector<int>> &prerequisites) {
        vector<int> ans;
        vector<int> inDegree(numCourses, 0);
        vector <vector<int>> graph(numCourses, vector<int>());
        for (auto x: prerequisites) {
            graph[x[1]].push_back(x[0]);
            inDegree[x[0]] += 1;
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int src = q.front();
            q.pop();
            ans.push_back(src);
            for (auto dest: graph[src]) {
                inDegree[dest] -= 1;
                if (inDegree[dest] == 0) {
                    q.push(dest);
                }
            }
        }
        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};
