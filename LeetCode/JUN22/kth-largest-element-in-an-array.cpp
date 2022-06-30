//
// Created by adeshchoudhar on 22/06/22.
//

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int ans;
        priority_queue<int> pq;
        for (int num: nums) {
            pq.push(num);
        }
        for (int i = 0; i < (k - 1); i++) {
            pq.pop();
        }
        ans = pq.top();
        return ans;
    }
};
