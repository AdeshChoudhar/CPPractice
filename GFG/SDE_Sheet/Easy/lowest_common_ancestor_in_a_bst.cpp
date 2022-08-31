// Function to find the lowest common ancestor in a BST.
Node *LCA(Node *root, int n1, int n2)
{
    Node *ans = root;
    if ((n1 < root->data) && (n2 < root->data))
    {
        ans = LCA(root->left, n1, n2);
    }
    else if ((n1 > root->data) && (n2 > root->data))
    {
        ans = LCA(root->right, n1, n2);
    }
    return ans;
}
