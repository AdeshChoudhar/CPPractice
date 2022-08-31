class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        bool ans = ((r1 == nullptr) && (r2 == nullptr));
        if ((r1 == nullptr) || (r2 == nullptr))
        {
            return ans;
        }
        ans = ((r1->data == r2->data) &&
               isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right));
        return ans;
    }
};
