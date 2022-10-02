//
// Created by adeshchoudhar on 24/9/22.
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
    vector <vector<int>> ans;

    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        pathSumUtil(root, targetSum, path, 0);
        return ans;
    }

    void pathSumUtil(TreeNode *root, int targetSum, vector<int> path, int currentSum) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        currentSum += root->val;
        if ((root->left == nullptr) && (root->right == nullptr) && (currentSum == targetSum)) {
            ans.push_back(path);
            path.clear();
            return;
        }
        pathSumUtil(root->left, targetSum, path, currentSum);
        pathSumUtil(root->right, targetSum, path, currentSum);
    }
};
