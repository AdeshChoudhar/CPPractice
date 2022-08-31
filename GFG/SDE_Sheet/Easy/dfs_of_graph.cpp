class Solution
{
public:
    vector<int> ans;
    vector<bool> vis;

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vis.resize(V, false);
        int u = 0;
        dfsOfGraphUtil(u, adj);
        return ans;
    }

    void dfsOfGraphUtil(int u, vector<int> adj[])
    {
        if (vis[u])
        {
            return;
        }
        vis[u] = true;
        ans.push_back(u);
        for (int v : adj[u])
        {
            dfsOfGraphUtil(v, adj);
        }
    }
};
