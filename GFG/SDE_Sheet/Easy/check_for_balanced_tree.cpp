class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        bool ans = isBalancedUtil(root).first;
        return ans;
    }

    pair<bool, int> isBalancedUtil(Node *root)
    {
        pair<bool, int> p = {true, 0};
        if (root == nullptr)
        {
            return p;
        }
        pair<bool, int> l = isBalancedUtil(root->left);
        pair<bool, int> r = isBalancedUtil(root->right);
        p.first = (l.first && r.first && (abs(l.second - r.second) <= 1));
        p.second = 1 + max(l.second, r.second);
        return p;
    }
};
