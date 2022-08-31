void leftViewUtil(Node *root, vector<int> &ans, map<int, int> &mp, int level)
{
    if (root == nullptr)
    {
        return;
    }
    if (mp.find(level) == mp.end())
    {
        mp[level] = root->data;
        ans.push_back(root->data);
    }
    leftViewUtil(root->left, ans, mp, level + 1);
    leftViewUtil(root->right, ans, mp, level + 1);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    map<int, int> mp;
    int level = 0;
    leftViewUtil(root, ans, mp, level);
    return ans;
}
