//
// Created by adeshchoudhar on 2/7/22.
//

class Solution {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        int ans, mod = 1000000007;
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long hm = horizontalCuts.front(), vm = verticalCuts.front();
        for (int i = 0, n = horizontalCuts.size(); i < (n - 1); i++) {
            hm = max((int) hm, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for (int i = 0, n = verticalCuts.size(); i < (n - 1); i++) {
            vm = max((int) vm, verticalCuts[i + 1] - verticalCuts[i]);
        }
        ans = ((hm % mod) * (vm % mod)) % mod;
        return ans;
    }
};
