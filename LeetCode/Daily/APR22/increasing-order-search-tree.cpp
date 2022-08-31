//
// Created by adeshchoudhar on 17/04/22.
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
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *ans = increasingBSTUtil(root, nullptr);
        return ans;
    }

    TreeNode *increasingBSTUtil(TreeNode *root, TreeNode *next) {
        if (root == nullptr) {
            return next;
        }
        TreeNode *res = increasingBSTUtil(root->left, root);
        root->left = nullptr;
        root->right = increasingBSTUtil(root->right, next);
        return res;
    }
};
