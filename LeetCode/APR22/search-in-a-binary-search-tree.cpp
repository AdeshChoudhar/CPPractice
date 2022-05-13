//
// Created by adeshchoudhar on 15/04/22.
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
    TreeNode *searchBST(TreeNode *root, int val) {
        TreeNode *ans = nullptr;
        if (root == nullptr) {
            return ans;
        }
        if (val < root->val) {
            ans = searchBST(root->left, val);
        } else if (val > root->val) {
            ans = searchBST(root->right, val);
        } else {
            ans = root;
        }
        return ans;
    }
};
