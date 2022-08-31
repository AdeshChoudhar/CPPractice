//
// Created by adeshchoudhar on 12/01/22.
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        TreeNode *newNode = new TreeNode(val);
        if (root == nullptr) {
            root = newNode;
            return root;
        }
        TreeNode *current = root, *previous = nullptr;
        while (current) {
            previous = current;
            if (val < current->val) {
                current = current->left;
            } else if (val > current->val) {
                current = current->right;
            }
        }
        if (val < previous->val) {
            previous->left = newNode;
        } else if (val > previous->val) {
            previous->right = newNode;
        }
        return root;
    }
};
