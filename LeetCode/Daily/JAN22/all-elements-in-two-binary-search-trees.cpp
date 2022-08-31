//
// Created by adeshchoudhar on 26/01/22.
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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> ans;
        queue<int> queue1, queue2;
        getAllElementsUtil(root1, queue1);
        getAllElementsUtil(root2, queue2);
        while (!queue1.empty() || !queue2.empty()) {
            if (queue1.empty()) {
                ans.push_back(queue2.front());
                queue2.pop();
            } else if (queue2.empty()) {
                ans.push_back(queue1.front());
                queue1.pop();
            } else {
                if (queue1.front() < queue2.front()) {
                    ans.push_back(queue1.front());
                    queue1.pop();
                } else {
                    ans.push_back(queue2.front());
                    queue2.pop();
                }
            }
        }
        return ans;
    }

    void getAllElementsUtil(TreeNode *n, queue<int> &q) {
        if (n == nullptr) {
            return;
        }
        getAllElementsUtil(n->left, q);
        q.push(n->val);
        getAllElementsUtil(n->right, q);
    }
};
