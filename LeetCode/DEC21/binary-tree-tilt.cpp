//
// Created by adeshchoudhar on 08/12/21.
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

    Solution() {
        this->ans = 0;
    }

    int findTilt(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        findTiltUtil(root);
        return this->ans;
    }

    int findTiltUtil(TreeNode *root) {
        int left = (root->left) ? findTiltUtil(root->left) : 0;
        int right = (root->right) ? findTiltUtil(root->right) : 0;
        int res = left + root->val + right;
        this->ans += abs(left - right);
        return res;
    }
};
