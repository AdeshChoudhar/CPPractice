//
// Created by adeshchoudhar on 17/10/21.
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
    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int ans = dfs(root, mp, sum, targetSum);
        return ans;
    }

    int dfs(TreeNode *root, unordered_map<int, int> &mp, int sum, int targetSum) {
        if (!root) {
            return 0;
        }

        sum += root->val;

        int cnt = 0;
        int remainingSum = sum - targetSum;
        if (mp[remainingSum]) {
            cnt += mp[remainingSum];
        }

        mp[sum] += 1;
        int left = dfs(root->left, mp, sum, targetSum);
        int right = dfs(root->right, mp, sum, targetSum);
        mp[sum] -= 1;

        return cnt + left + right;
    }
};
