//
// Created by adeshchoudhar on 10/8/22.
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *ans = sortedArrayToBSTUtil(nums, 0, nums.size() - 1);
        return ans;
    }

    TreeNode *sortedArrayToBSTUtil(vector<int> &nums, int l, int r) {
        TreeNode *res = nullptr;
        if (l > r) {
            return res;
        }
        int m = l + (r - l) / 2;
        res = new TreeNode(nums[m]);
        res->left = sortedArrayToBSTUtil(nums, l, m - 1);
        res->right = sortedArrayToBSTUtil(nums, m + 1, r);
        return res;
    }
};
