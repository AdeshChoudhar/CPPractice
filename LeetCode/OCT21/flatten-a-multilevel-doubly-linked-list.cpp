//
// Created by adeshchoudhar on 31/10/21.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flatten(Node *head) {
        Node *current = head;
        while (current) {
            if (current->child) {
                Node *current_child = current->child;
                while (current_child->next) {
                    current_child = current_child->next;
                }
                current_child->next = current->next;
                if (current->next) {
                    current->next->prev = current_child;
                }
                current->next = current->child;
                current->next->prev = current;
                current->child = nullptr;
            }
            current = current->next;
        }
        return head;
    }
};
