//
// Created by adeshchoudhar on 15/12/21.
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *new_head = new ListNode(0);
        ListNode *previous = new_head, *tmp;
        while (head != nullptr) {
            tmp = head->next;
            if (previous->val >= head->val) {
                previous = new_head;
            }
            while (previous->next && previous->next->val < head->val) {
                previous = previous->next;
            }
            head->next = previous->next;
            previous->next = head;
            head = tmp;
        }
        return new_head->next;
    }
};
