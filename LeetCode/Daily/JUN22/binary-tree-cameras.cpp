//
// Created by adeshchoudhar on 17/06/22.
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

    int minCameraCover(TreeNode *root) {
        ans = 0;
        ans += (minCameraCoverUtil(root) == 0) ? 1 : 0;
        return ans;
    }

    int minCameraCoverUtil(TreeNode *root) {
        if (root == nullptr) {
            return 2;
        }
        int l = minCameraCoverUtil(root->left);
        int r = minCameraCoverUtil(root->right);
        if ((l == 0) || (r == 0)) {
            ans += 1;
            return 1;
        } else if ((l == 1) || (r == 1)) {
            return 2;
        }
        return 0;
    }
};
