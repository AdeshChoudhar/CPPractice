//
// Created by adeshchoudhar on 5/9/22.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector <vector<int>> levelOrder(Node *root) {
        vector <vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue < Node * > q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back(vector<int>());
            for (int i = 0, n = q.size(); i < n; i++) {
                Node *cur = q.front();
                q.pop();
                ans.back().push_back(cur->val);
                for (Node *child: cur->children) {
                    q.push(child);
                }
            }
        }
        return ans;
    }
};
