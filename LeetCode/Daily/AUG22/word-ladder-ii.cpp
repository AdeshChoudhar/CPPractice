//
// Created by adeshchoudhar on 14/8/22.
//

class Solution {
public:
    vector <vector<string>> findLadders(string beginWord, string endWord, vector <string> &wordList) {
        vector <vector<string>> ans;
        int n = wordList.size();
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (end == n) {
            return ans;
        }
        int start = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if (start == n) {
            wordList.emplace(wordList.begin(), beginWord);
            start = 0;
            end += 1;
            n += 1;
        }
        vector <vector<int>> graph(n, vector<int>()), paths;
        vector<int> parent[n], path;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (valid(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        bfs(graph, parent, n, start);
        shortestPaths(paths, path, parent, end);
        for (auto u: paths) {
            vector <string> path;
            for (int i = 0, m = u.size(); i < m - 1; i++) {
                path.push_back(wordList[u[i]]);
            }
            reverse(path.begin(), path.end());
            path.push_back(wordList[end]);
            ans.push_back(path);
        }
        return ans;
    }

    bool valid(string s, string t) {
        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            c += (s[i] != t[i]);
        }
        return (c == 1);
    }

    void bfs(vector <vector<int>> &g, vector<int> parent[], int n, int start) {
        vector<int> dist(n, 1005);
        queue<int> q;
        q.push(start);
        parent[start] = {-1};
        dist[start] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int u: g[x]) {
                if (dist[u] > dist[x] + 1) {
                    dist[u] = dist[x] + 1;
                    q.push(u);
                    parent[u].clear();
                    parent[u].push_back(x);
                } else if (dist[u] == dist[x] + 1) {
                    parent[u].push_back(x);
                }
            }
        }
    }

    void shortestPaths(vector <vector<int>> &paths, vector<int> &path, vector<int> parent[], int node) {
        if (node == -1) {
            paths.push_back(path);
            return;
        }
        for (auto u: parent[node]) {
            path.push_back(u);
            shortestPaths(paths, path, parent, u);
            path.pop_back();
        }
    }
};
