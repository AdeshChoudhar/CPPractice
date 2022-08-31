//
// Created by adeshchoudhar on 17/05/22.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    deque<int> path;

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        TreeNode *ans = cloned;
        bool flag = getTargetCopyUtil(original, target);
        for (int i = 0, n = path.size(); i < n; i++) {
            if (path.front() == -1) {
                ans = ans->left;
            } else {
                ans = ans->right;
            }
            path.pop_front();
        }
        return ans;
    }

    bool getTargetCopyUtil(TreeNode *root, TreeNode *target) {
        if (root == nullptr) {
            return false;
        }
        if (root == target) {
            return true;
        }
        path.push_back(-1);
        if (getTargetCopyUtil(root->left, target)) {
            return true;
        }
        path.pop_back();
        path.push_back(1);
        if (getTargetCopyUtil(root->right, target)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};
