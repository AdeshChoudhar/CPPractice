//
// Created by adeshchoudhar on 13/05/22.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root) {
        Node *curr = root, *prev, *child, *next;
        while (curr) {
            while (curr->next && !curr->left && !curr->right) {
                curr = curr->next;
            }
            prev = curr->left ? curr->left : curr->right;
            child = curr->left ? curr->left : curr->right;
            while (child) {
                if (curr->right && child != curr->right) {
                    next = curr->right;
                } else {
                    curr = curr->next;
                    while (curr && !curr->left && !curr->right) {
                        curr = curr->next;
                    }
                    next = curr ? (curr->left ? curr->left : curr->right) : curr;
                }
                child->next = next;
                child = next;
            }
            curr = prev;
        }
        return root;
    }
};
