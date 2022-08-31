//
// Created by adeshchoudhar on 23/01/22.
//

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q({12, 23, 34, 45, 56, 67, 78, 89});
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (current > high) {
                break;
            }
            if (low <= current && current <= high) {
                ans.push_back(current);
            }
            if (current % 10 < 9) {
                q.push(current * 10 + (current % 10) + 1);
            }
        }
        return ans;
    }
};
