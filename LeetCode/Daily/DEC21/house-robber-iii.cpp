//
// Created by adeshchoudhar on 05/12/21.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode *root) {
        int l, r;
        int ans = robUtil(root, l, r);
        return ans;
    }

    int robUtil(TreeNode *root, int &l, int &r) {
        if (root == nullptr) {
            return 0;
        }
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = robUtil(root->left, ll, lr);
        r = robUtil(root->right, rl, rr);
        return max((root->val + ll + lr + rl + rr), (l + r));
    }
};
