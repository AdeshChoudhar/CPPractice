//
// Created by adeshchoudhar on 20/03/22.
//

class Solution {
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        int ans = -1, n = tops.size();
        vector<int> t(7), b(7), c(7);
        for (int i = 0; i < n; i++) {
            t[tops[i]] += 1;
            b[bottoms[i]] += 1;
            if (tops[i] == bottoms[i]) {
                c[tops[i]] += 1;
            }
        }
        for (int i = 1; i < 7; i++) {
            if ((t[i] + b[i] - c[i]) == n) {
                ans = n - max(t[i], b[i]);
                break;
            }
        }
        return ans;
    }
};
