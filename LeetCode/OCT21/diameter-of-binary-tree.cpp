//
// Created by adeshchoudhar on 11/10/21.
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
    int diameter;

    Solution() {
        diameter = 0;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        heightOfBinaryTree(root);
        return diameter;
    }

    int heightOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = heightOfBinaryTree(root->left);
        int right_height = heightOfBinaryTree(root->right);
        diameter = max(diameter, left_height + right_height);
        return 1 + max(left_height, right_height);
    }
};
