//
// Created by adeshchoudhar on 15/05/22.
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
    int depth;

    int deepestLeavesSum(TreeNode *root) {
        ans = 0;
        depth = deepestLeavesHeight(root);
        deepestLeavesSumUtil(root, 1);
        return ans;
    }

    int deepestLeavesHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(deepestLeavesHeight(root->left), deepestLeavesHeight(root->right));
    }

    void deepestLeavesSumUtil(TreeNode *root, int d) {
        if (root == nullptr) {
            return;
        }
        if (d == depth) {
            ans += root->val;
        }
        deepestLeavesSumUtil(root->left, d + 1);
        deepestLeavesSumUtil(root->right, d + 1);
    }
};
