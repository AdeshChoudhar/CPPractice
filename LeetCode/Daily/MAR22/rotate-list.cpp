//
// Created by adeshchoudhar on 11/03/22.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 0;
        ListNode *current = head, *tail = nullptr;
        while (current) {
            n += 1;
            tail = current;
            current = current->next;
        }
        tail->next = head;
        k %= n;
        if (k) {
            for (int i = 0; i < (n - k); i++) {
                tail = tail->next;
            }
        }
        ListNode *ans = tail->next;
        tail->next = nullptr;
        return ans;
    }
};
