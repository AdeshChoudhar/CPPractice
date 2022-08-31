//
// Created by adeshchoudhar on 22/7/22.
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *ans, *hl = new ListNode(), *hm = new ListNode();
        ListNode *ch = head, *cl = hl, *cm = hm;
        while (ch != nullptr) {
            if (ch->val < x) {
                cl->next = ch;
                cl = cl->next;
            } else {
                cm->next = ch;
                cm = cm->next;
            }
            ch = ch->next;
        }
        cm->next = nullptr;
        cl->next = hm->next;
        ans = hl->next;
        return ans;
    }
};
