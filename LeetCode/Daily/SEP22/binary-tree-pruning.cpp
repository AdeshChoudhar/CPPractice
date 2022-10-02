//
// Created by adeshchoudhar on 6/9/22.
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
    TreeNode *pruneTree(TreeNode *root) {
        TreeNode *ans = nullptr;
        if (root == nullptr) {
            return ans;
        }
        ans = root;
        ans->left = pruneTree(root->left);
        ans->right = pruneTree(root->right);
        if ((root->left == nullptr) && (root->right == nullptr) && (root->val == 0)) {
            ans = nullptr;
        }
        return ans;
    }
};
