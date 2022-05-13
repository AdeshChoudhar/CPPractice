//
// Created by adeshchoudhar on 13/10/21.
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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        stack < TreeNode * > s;
        TreeNode *root = new TreeNode(preorder[0]);
        s.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode *tmp = nullptr;
            while (!s.empty() && preorder[i] > s.top()->val) {
                tmp = s.top();
                s.pop();
            }
            if (tmp) {
                tmp->right = new TreeNode(preorder[i]);
                s.push(tmp->right);
            } else {
                s.top()->left = new TreeNode(preorder[i]);
                s.push(s.top()->left);
            }
        }
        return root;
    }
};
