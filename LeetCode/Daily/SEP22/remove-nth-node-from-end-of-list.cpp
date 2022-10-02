//
// Created by adeshchoudhar on 28/9/22.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *slow = head, *fast = head, *previous;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            previous = head;
            head = head->next;
        } else {
            while (fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            previous = slow->next;
            slow->next = slow->next->next;
        }
        previous->next = nullptr;
        delete previous;
        return head;
    }
};
