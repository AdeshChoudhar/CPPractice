//
// Created by adeshchoudhar on 12/03/22.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        Node *current = head, *tmp;
        while (current) {
            tmp = current->next;
            current->next = new Node(current->val);
            current->next->next = tmp;
            current = tmp;
        }
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        Node *ans = new Node(0);
        current = ans, tmp = head;
        while (tmp) {
            current->next = tmp->next;
            current = current->next;
            tmp->next = tmp->next->next;
            tmp = tmp->next;
        }
        return ans->next;
    }
};
