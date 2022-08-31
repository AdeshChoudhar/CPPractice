//
// Created by adeshchoudhar on 16/11/21.
//

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n, mid, ans;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (solve(m, n, mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    int solve(int m, int n, int x) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(x / i, n);
        }
        return cnt;
    }
};
