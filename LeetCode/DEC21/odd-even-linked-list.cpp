//
// Created by adeshchoudhar on 02/12/21.
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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *odd = head, *even = head->next, *tmp = head;
        ListNode *odd_current = odd, *even_current = even;
        while (odd_current && even_current) {
            if (odd_current->next) {
                odd_current->next = odd_current->next->next;
            }
            if (even_current->next) {
                even_current->next = even_current->next->next;
            }
            tmp = odd_current;
            odd_current = odd_current->next;
            even_current = even_current->next;
        }
        if (odd_current && tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = even;
        return odd;
    }
};
