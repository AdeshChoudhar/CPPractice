//
// Created by adeshchoudhar on 23/8/22.
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
    bool isPalindrome(ListNode *head) {
        bool ans = true;
        if ((head == nullptr) || (head->next == nullptr)) {
            return ans;
        }
        ListNode *slow = head, *fast = head;
        while ((fast->next != nullptr) && (fast->next->next != nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverseList(slow->next);
        slow = head;
        while (fast != nullptr) {
            if (slow->val != fast->val) {
                ans = false;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return ans;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
