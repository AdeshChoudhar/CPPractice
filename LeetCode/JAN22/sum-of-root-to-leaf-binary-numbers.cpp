//
// Created by adeshchoudhar on 11/01/22.
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

    int sumRootToLeaf(TreeNode *root) {
        ans = 0;
        string binary = "";
        dfs(root, binary);
        return ans;
    }

    void dfs(TreeNode *root, string binary) {
        binary.push_back(root->val + '0');
        if ((root->left == nullptr) && (root->right == nullptr)) {
            int res = 0;
            for (int i = 0, n = binary.size(); i < n; i++) {
                if (binary[i] == '1') {
                    res += pow(2, n - 1 - i);
                }
            }
            ans += res;
        }
        if (root->left) {
            dfs(root->left, binary);
        }
        if (root->right) {
            dfs(root->right, binary);
        }
    }
};
