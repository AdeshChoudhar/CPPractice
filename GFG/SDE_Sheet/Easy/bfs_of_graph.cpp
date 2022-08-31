class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            for (int i = 0, n = q.size(); i < n; i++)
            {
                int u = q.front();
                q.pop();
                if (!vis[u])
                {
                    ans.push_back(u);
                    for (int v : adj[u])
                    {
                        q.push(v);
                    }
                }
                vis[u] = true;
            }
        }
        return ans;
    }
};
