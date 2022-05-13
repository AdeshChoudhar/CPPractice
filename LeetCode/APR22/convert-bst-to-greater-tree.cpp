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
    int sum;

    TreeNode *convertBST(TreeNode *root) {
        sum = 0;
        convertBSTUtil(root);
        return root;
    }

    void convertBSTUtil(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        if (root->right) {
            convertBSTUtil(root->right);
        }
        sum += root->val;
        root->val = sum;
        if (root->left) {
            convertBSTUtil(root->left);
        }
    }
};
