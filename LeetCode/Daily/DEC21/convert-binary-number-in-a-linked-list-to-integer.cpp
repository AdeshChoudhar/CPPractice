//
// Created by adeshchoudhar on 07/12/21.
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
    int getDecimalValue(ListNode *head) {
        int length = 0;
        ListNode *current = head;
        while (current) {
            length += 1;
            current = current->next;
        }
        int ans = 0, i = 0;
        current = head;
        while (current) {
            if (current->val == 1) {
                ans += (int) pow(2, length - 1 - i);
            }
            current = current->next;
            i += 1;
        }
        return ans;
    }
};
