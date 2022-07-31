//
// Created by adeshchoudhar on 11/7/22.
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        rightSideViewUtil(root, ans, 0);
        return ans;
    }

    void rightSideViewUtil(TreeNode *root, vector<int> &ans, int level) {
        if (root == nullptr) {
            return;
        }
        if (ans.size() <= level) {
            ans.push_back(root->val);
        }
        rightSideViewUtil(root->right, ans, level + 1);
        rightSideViewUtil(root->left, ans, level + 1);
    }
};
