//
// Created by adeshchoudhar on 31/12/21.
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
    int maxAncestorDiff(TreeNode *root) {
        int ans = maxAncestorDiffUtil(root, root->val, root->val);
        return ans;
    }

    int maxAncestorDiffUtil(TreeNode *root, int mini, int maxi) {
        if (root == nullptr) {
            return maxi - mini;
        }
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        return max(maxAncestorDiffUtil(root->left, mini, maxi), maxAncestorDiffUtil(root->right, mini, maxi));
    }
};
