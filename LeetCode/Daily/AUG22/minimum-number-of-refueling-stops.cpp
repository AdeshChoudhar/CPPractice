//
// Created by adeshchoudhar on 20/8/22.
//

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector <vector<int>> &stations) {
        int ans = 0, n = stations.size(), dis = startFuel;
        priority_queue<int> pq;
        for (int i = 0; dis < target;) {
            for (; (i < n) && (stations[i][0] <= dis); i++) {
                pq.push(stations[i][1]);
            }
            if (pq.empty()) {
                ans = -1;
                break;
            }
            dis += pq.top();
            pq.pop();
            ans += 1;
        }
        return ans;
    }
};
