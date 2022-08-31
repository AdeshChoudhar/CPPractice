//
// Created by adeshchoudhar on 22/12/21.
//

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head->next) {
            return;
        }
        ListNode *middle = middleNode(head);
        ListNode *first = head->next, *second = reverseList(middle);
        for (int i = 0; first != second; i++) {
            if (i & 1) {
                head->next = first;
                first = first->next;
            } else {
                head->next = second;
                second = second->next;
            }
            head = head->next;
        }
    }

    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *previous = nullptr, *tmp;
        while (head) {
            tmp = head->next;
            head->next = previous;
            previous = head;
            head = tmp;
        }
        return previous;
    }
};
