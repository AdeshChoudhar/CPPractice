//
// Created by adeshchoudhar on 21/01/22.
//

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0, tank = 0, cnt = 0;
        for (int i = 0, n = gas.size(); i < n; i++) {
            tank += (gas[i] - cost[i]);
            cnt += (gas[i] - cost[i]);
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        int ans = (cnt >= 0) ? start : -1;
        return ans;
    }
};
