//
// Created by adeshchoudhar on 26/7/22.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *ans = root;
        if ((root == nullptr) || (root == p) || (root == q)) {
            return ans;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if ((left == nullptr) || (right == nullptr)) {
            ans = (left != nullptr) ? left : right;
        }
        return ans;
    }
};
