//
// Created by adeshchoudhar on 18/04/22.
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
    int kthSmallest(TreeNode *root, int k) {
        int ans;
        stack < TreeNode * > s;
        TreeNode *current = root;
        while (true) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            k -= 1;
            if (k == 0) {
                ans = current->val;
                break;
            }
            current = current->right;
        }
        return ans;
    }
};
