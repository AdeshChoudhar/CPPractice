//
// Created by adeshchoudhar on 11/8/22.
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
    bool isValidBST(TreeNode *root) {
        bool ans = isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
        return ans;
    }

    bool isValidBSTUtil(TreeNode *root, long long int mnm, long long int mxm) {
        bool res = true;
        if (root == nullptr) {
            return res;
        }
        long long int val = (long long int) root->val;
        res = (res && (mnm < val) && (val < mxm));
        res = (res && isValidBSTUtil(root->left, mnm, val));
        res = (res && isValidBSTUtil(root->right, val, mxm));
        return res;
    }
};
