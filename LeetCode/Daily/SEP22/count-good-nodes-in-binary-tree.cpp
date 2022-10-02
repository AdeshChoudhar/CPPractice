//
// Created by adeshchoudhar on 1/9/22.
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
    int ans;

    int goodNodes(TreeNode *root) {
        ans = 0;
        goodNodesUtil(root, INT_MIN);
        return ans;
    }

    void goodNodesUtil(TreeNode *root, int mxm) {
        if (root == nullptr) {
            return;
        }
        if (root->val >= mxm) {
            ans += 1;
            mxm = root->val;
        }
        goodNodesUtil(root->left, mxm);
        goodNodesUtil(root->right, mxm);
    }
};
