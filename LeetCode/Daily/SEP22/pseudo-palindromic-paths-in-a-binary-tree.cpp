//
// Created by adeshchoudhar on 14/9/22.
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
    int pseudoPalindromicPaths(TreeNode *root) {
        int ans = pseudoPalindromicPathsUtil(root, 0);
        return ans;
    }

    int pseudoPalindromicPathsUtil(TreeNode *root, int val) {
        int res = 0;
        if (root == nullptr) {
            return res;
        }
        val ^= (1 << (root->val - 1));
        res += pseudoPalindromicPathsUtil(root->left, val);
        res += pseudoPalindromicPathsUtil(root->right, val);
        res += (int) ((root->left == root->right) && ((val & (val - 1)) == 0));
        return res;
    }
};
