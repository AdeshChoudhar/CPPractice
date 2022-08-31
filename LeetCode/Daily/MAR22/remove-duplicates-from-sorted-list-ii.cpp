//
// Created by adeshchoudhar on 09/03/22.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int v = head->val;
        ListNode *current = head->next;
        if (current->val != v) {
            head->next = deleteDuplicates(current);
            return head;
        } else {
            while (current && current->val == v) {
                current = current->next;
            }
            return deleteDuplicates(current);
        }
    }
};
