//
// Created by adeshchoudhar on 19/04/22.
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
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *previous = nullptr;

    void recoverTree(TreeNode *root) {
        recoverTreeUtil(root);
        first->val = first->val ^ second->val;
        second->val = first->val ^ second->val;
        first->val = first->val ^ second->val;
    }

    void recoverTreeUtil(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        recoverTreeUtil(root->left);
        if (previous) {
            if (root->val < previous->val) {
                if (first == nullptr) {
                    first = previous;
                }
                second = root;
            }
        }
        previous = root;
        recoverTreeUtil(root->right);
    }
};
