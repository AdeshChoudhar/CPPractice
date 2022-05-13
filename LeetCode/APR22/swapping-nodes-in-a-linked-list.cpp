//
// Created by adeshchoudhar on 05/04/22.
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
    ListNode *swapNodes(ListNode *head, int k) {
        vector<int> v;
        ListNode *current = head;
        while (current) {
            v.push_back(current->val);
            current = current->next;
        }
        swap(v[k - 1], v[v.size() - k]);
        int i = 0;
        current = head;
        while (current) {
            current->val = v[i++];
            current = current->next;
        }
        return head;
    }
};
