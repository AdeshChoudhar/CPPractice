//
// Created by adeshchoudhar on 24/02/22.
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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }

    ListNode *merge(ListNode *first, ListNode *second) {
        ListNode dummy(0);
        ListNode *current = &dummy;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                current->next = first;
                first = first->next;
            } else {
                current->next = second;
                second = second->next;
            }
            current = current->next;
        }
        if (first != nullptr) {
            current->next = first;
        } else {
            current->next = second;
        }
        return dummy.next;
    }
};
