//
// Created by adeshchoudhar on 2/9/22.
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
    map<int, vector<long long>> mp;

    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        int level = 0;
        averageOfLevelsUtil(root, level);
        for (auto x: mp) {
            vector<long long> v = x.second;
            ans.push_back(accumulate(v.begin(), v.end(), 0LL) / (double) v.size());
        }
        return ans;
    }

    void averageOfLevelsUtil(TreeNode *root, int level) {
        if (root == nullptr) {
            return;
        }
        mp[level].push_back(root->val);
        averageOfLevelsUtil(root->left, level + 1);
        averageOfLevelsUtil(root->right, level + 1);
    }
};
