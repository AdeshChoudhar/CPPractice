int countLeaves(Node *root)
{
    int ans = 0;
    if (root == nullptr)
    {
        return ans;
    }
    ans += (int)((root->left == nullptr) && (root->right == nullptr));
    ans += countLeaves(root->left);
    ans += countLeaves(root->right);
    return ans;
}
