class Solution
{
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node *root)
    {
        bool ans = isSymmetricUtil(root, root);
        return ans;
    }

    bool isSymmetricUtil(struct Node *l, struct Node *r)
    {
        bool res = ((l == nullptr) && (r == nullptr));
        if ((l == nullptr) || (r == nullptr))
        {
            return res;
        }
        res = (l->data == r->data) &&
              isSymmetricUtil(l->left, r->right) &&
              isSymmetricUtil(l->right, r->left);
        return res;
    }
};
