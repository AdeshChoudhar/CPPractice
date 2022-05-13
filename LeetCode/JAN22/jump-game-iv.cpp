//
// Created by adeshchoudhar on 15/01/22.
//

class Solution {
public:
    int minJumps(vector<int> &arr) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0, n = arr.size(); i < n; i++) {
            graph[arr[i]].push_back(i);
        }
        int ans = 0;
        vector<bool> visited(arr.size(), false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            for (int i = 0, n = q.size(); i < n; i++) {
                int front = q.front();
                q.pop();
                if (front == (arr.size() - 1)) {
                    return ans;
                }
                vector<int> &next = graph[arr[front]];
                next.push_back(front - 1);
                next.push_back(front + 1);
                for (auto j: next) {
                    if (j >= 0 && j <= arr.size() && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            ans += 1;
        }
        return 0;
    }
};
