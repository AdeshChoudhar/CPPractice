//
// Created by adeshchoudhar on 27/02/22.
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
    int widthOfBinaryTree(TreeNode *root) {
        int ans = 0;
        queue <pair<TreeNode *, long long>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *tmp;
            int maxi = INT_MIN, mini = INT_MAX, width;
            for (int i = 0, n = q.size(); i < n; i++) {
                tmp = q.front().first;
                width = q.front().second;
                q.pop();
                maxi = max(maxi, width);
                mini = min(mini, width);
                if (tmp->left) {
                    q.push(make_pair(tmp->left, (long long) 2 * width + 1));
                }
                if (tmp->right) {
                    q.push(make_pair(tmp->right, (long long) 2 * width + 2));
                }
            }
            ans = max(ans, maxi - mini + 1);
        }
        return ans;
    }
};
