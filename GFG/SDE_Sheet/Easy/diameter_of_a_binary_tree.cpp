class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        int ans = 0;
        ans = diameterUtil(root).first;
        return ans;
    }

    pair<int, int> diameterUtil(Node *root)
    {
        pair<int, int> p = {0, 0};
        if (root == nullptr)
        {
            return p;
        }
        pair<int, int> l = diameterUtil(root->left);
        pair<int, int> r = diameterUtil(root->right);
        p.first = max({l.first, r.first, 1 + l.second + r.second});
        p.second = 1 + max(l.second, r.second);
        return p;
    }
};
