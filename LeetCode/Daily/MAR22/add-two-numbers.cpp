//
// Created by adeshchoudhar on 10/03/22.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        int sum = l1->val + l2->val;
        ListNode *ans = new ListNode(sum % 10);
        ans->next = addTwoNumbers(l1->next, l2->next);
        if (sum >= 10) {
            ans->next = addTwoNumbers(ans->next, new ListNode(1));
        }
        return ans;
    }
};
