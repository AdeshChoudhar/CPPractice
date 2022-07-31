//
// Created by adeshchoudhar on 13/7/22.
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
    map<int, vector<int>> mp;

    vector <vector<int>> levelOrder(TreeNode *root) {
        vector <vector<int>> ans;
        mp.clear();
        int level = 0;
        levelOrderUtil(root, level);
        for (auto x: mp) {
            ans.push_back(x.second);
        }
        return ans;
    }

    void levelOrderUtil(TreeNode *root, int level) {
        if (root == nullptr) {
            return;
        }
        mp[level].push_back(root->val);
        levelOrderUtil(root->left, level + 1);
        levelOrderUtil(root->right, level + 1);
    }
};
