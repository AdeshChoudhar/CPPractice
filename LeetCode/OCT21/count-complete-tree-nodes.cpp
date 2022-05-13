//
// Created by adeshchoudhar on 24/10/21.
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
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = 0, rightHeight = 0;
        TreeNode *tmp1 = root, *tmp2 = root;
        while (tmp1) {
            tmp1 = tmp1->left;
            leftHeight += 1;
        }
        while (tmp2) {
            tmp2 = tmp2->right;
            rightHeight += 1;
        }

        if (leftHeight == rightHeight) {
            return (int) pow(2, leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
