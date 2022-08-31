//
// Created by adeshchoudhar on 14/7/22.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *ans = buildTreeUtil(preorder, inorder, 0, inorder.size() - 1, 0);
        return ans;
    }

    TreeNode *buildTreeUtil(vector<int> &preorder, vector<int> &inorder, int is, int ie, int ps) {
        if ((ps == preorder.size()) || (is > ie)) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[ps]);
        int ir = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        root->left = buildTreeUtil(preorder, inorder, is, ir - 1, ps + 1);
        root->right = buildTreeUtil(preorder, inorder, ir + 1, ie, ps + 1 + (ir - is));
        return root;
    }
};
