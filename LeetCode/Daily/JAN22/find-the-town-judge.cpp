//
// Created by adeshchoudhar on 03/01/22.
//

class Solution {
public:
    int findJudge(int n, vector <vector<int>> &trust) {
        vector<int> v(n + 1, 0);
        for (auto x: trust) {
            v[x[0]] -= 1;
            v[x[1]] += 1;
        }
        int ans = -1;
        for (int i = 1; i < n + 1; i++) {
            if (v[i] == n - 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
