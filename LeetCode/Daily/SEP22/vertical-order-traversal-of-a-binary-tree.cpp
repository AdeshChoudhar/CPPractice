//
// Created by adeshchoudhar on 4/9/22.
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
    map<int, map<int, multiset < int>>>
    mp;

    vector <vector<int>> verticalTraversal(TreeNode *root) {
        vector <vector<int>> ans;
        int row = 0, col = 0;
        verticalTraversalUtil(root, row, col);
        for (auto x: mp) {
            vector<int> v;
            for (auto y: x.second) {
                v.insert(v.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }

    void verticalTraversalUtil(TreeNode *root, int row, int col) {
        if (root == nullptr) {
            return;
        }
        mp[col][row].insert(root->val);
        verticalTraversalUtil(root->left, row + 1, col - 1);
        verticalTraversalUtil(root->right, row + 1, col + 1);
    }
};
