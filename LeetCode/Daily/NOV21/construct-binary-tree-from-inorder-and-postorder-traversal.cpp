//
// Created by adeshchoudhar on 21/11/21.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeUtil(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode *
    buildTreeUtil(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
        if ((inStart > inEnd) || (postStart > postEnd)) {
            return nullptr;
        }

        int tmp = inStart;
        while (inorder[tmp] != postorder[postEnd]) {
            tmp += 1;
        }
        TreeNode *newNode = new TreeNode(postorder[postEnd]);
        newNode->left = buildTreeUtil(inorder, inStart, tmp - 1, postorder, postStart, postStart + tmp - inStart - 1);
        newNode->right = buildTreeUtil(inorder, tmp + 1, inEnd, postorder, postStart + tmp - inStart, postEnd - 1);
        return newNode;
    }
};
