//
// Created by adeshchoudhar on 03/11/21.
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int ans = getSum(root, 0);
        return ans;
    }

    int getSum(TreeNode *root, int currentSum) {
        if (root == nullptr) {
            return 0;
        }
        int newSum = currentSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return newSum;
        }
        return getSum(root->left, newSum) + getSum(root->right, newSum);
    }
};
