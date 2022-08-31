class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        bool ans = isBSTUtil(root, INT_MIN, INT_MAX);
        return ans;
    }

    bool isBSTUtil(Node *root, int mnm, int mxm)
    {
        return (root == nullptr) ||
               ((mnm < root->data) && (root->data < mxm) &&
                isBSTUtil(root->left, mnm, root->data) &&
                isBSTUtil(root->right, root->data, mxm));
    }
};
