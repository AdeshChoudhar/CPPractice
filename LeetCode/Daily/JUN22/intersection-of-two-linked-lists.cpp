//
// Created by adeshchoudhar on 06/06/22.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans, *currentA = headA, *currentB = headB;
        while (currentA != currentB) {
            currentA = (currentA != nullptr) ? currentA->next : headB;
            currentB = (currentB != nullptr) ? currentB->next : headA;
        }
        ans = currentA;
        return ans;
    }
};
