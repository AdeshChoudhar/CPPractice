//
// Created by adeshchoudhar on 29/12/21.
//

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue < Node * > q;
        q.push(root);
        while (!q.empty()) {
            Node *rightNode = nullptr;
            for (int i = 0, n = q.size(); i < n; i++) {
                Node *currentNode = q.front();
                q.pop();
                currentNode->next = rightNode;
                rightNode = currentNode;
                if (currentNode->right) {
                    q.push(currentNode->right);
                    q.push(currentNode->left);
                }
            }
        }
        return root;
    }
};
