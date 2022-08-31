//
// Created by adeshchoudhar on 19/02/22.
//

class Solution {
public:
    int minimumDeviation(vector<int> &nums) {
        int ans = INT_MAX, mini = INT_MAX;
        priority_queue<int> pq;
        for (auto num: nums) {
            num = num % 2 ? num * 2 : num;
            pq.push(num);
            mini = min(mini, num);
        }
        while (pq.top() % 2 == 0) {
            ans = min(ans, pq.top() - mini);
            mini = min(mini, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        ans = min(ans, pq.top() - mini);
        return ans;
    }
};
