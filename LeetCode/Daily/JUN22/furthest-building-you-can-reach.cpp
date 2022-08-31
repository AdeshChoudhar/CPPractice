//
// Created by adeshchoudhar on 21/06/22.
//

class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        int ans = 0, n = heights.size(), d;
        priority_queue<int> pq;
        while (ans < (n - 1)) {
            d = heights[ans + 1] - heights[ans];
            if (d > 0) {
                pq.push(-1 * d);
            }
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            if (bricks < 0) {
                break;
            }
            ans += 1;
        }
        ans = (bricks >= 0) ? (n - 1) : ans;
        return ans;
    }
};
