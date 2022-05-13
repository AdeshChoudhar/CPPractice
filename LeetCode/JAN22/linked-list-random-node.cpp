//
// Created by adeshchoudhar on 07/01/22.
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
    vector<int> nums;

    Solution(ListNode *head) {
        nums.clear();
        ListNode *currentNode = head;
        while (currentNode) {
            nums.push_back(currentNode->val);
            currentNode = currentNode->next;
        }
    }

    int getRandom() {
        int ind = rand() % nums.size();
        int ans = nums[ind];
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
