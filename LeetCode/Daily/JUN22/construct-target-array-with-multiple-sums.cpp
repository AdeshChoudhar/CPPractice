//
// Created by adeshchoudhar on 24/06/22.
//

class Solution {
public:
    bool isPossible(vector<int> &target) {
        bool ans, flag = true;
        long long sum = 0;
        for (int x: target) {
            sum += x;
        }
        priority_queue<int> pq(target.begin(), target.end());
        while ((sum > 1) && (pq.top() > (sum / 2))) {
            int top = pq.top();
            pq.pop();
            sum -= top;
            if (sum <= 1) {
                ans = bool(sum);
                flag = false;
                break;
            }
            pq.push(top % sum);
            sum += (top % sum);
        }
        if (flag) {
            ans = (sum == target.size());
        }
        return ans;
    }
};
