//
// Created by adeshchoudhar on 18/10/21.
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
    int x_depth = 0;
    int y_depth = 0;
    TreeNode *x_parent = nullptr;
    TreeNode *y_parent = nullptr;

    bool isCousins(TreeNode *root, int x, int y) {
        solve(root, x, y, 0, nullptr);
        return (x_depth == y_depth) && (x_parent != y_parent);
    }

    void solve(TreeNode *root, int x, int y, int depth, TreeNode *parent) {
        if (root == nullptr) {
            return;
        }
        if (root->val == x) {
            x_depth = depth;
            x_parent = parent;
        } else if (root->val == y) {
            y_depth = depth;
            y_parent = parent;
        } else {
            solve(root->left, x, y, depth + 1, root);
            solve(root->right, x, y, depth + 1, root);
        }
    }
};
