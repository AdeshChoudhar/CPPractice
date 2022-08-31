vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    map<int, vector<int>> mp;
    queue<pair<int, Node *>> q;
    q.push(make_pair(0, root));
    while (!q.empty())
    {
        for (int i = 0, n = q.size(); i < n; i++)
        {
            pair<int, Node *> x = q.front();
            q.pop();
            int level = x.first;
            Node *node = x.second;
            mp[level].push_back(node->data);
            if (node->left)
            {
                q.push(make_pair(level + 1, node->left));
            }
            if (node->right)
            {
                q.push(make_pair(level + 1, node->right));
            }
        }
    }
    for (auto x : mp)
    {
        if (x.first & 1)
        {
            for (auto it = x.second.begin(); it != x.second.end(); it++)
            {
                ans.push_back(*it);
            }
        }
        else
        {
            for (auto it = x.second.rbegin(); it != x.second.rend(); it++)
            {
                ans.push_back(*it);
            }
        }
    }
    return ans;
}
