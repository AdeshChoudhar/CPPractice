//
// Created by adeshchoudhar on 08/11/21.
//

class Solution {
public:
    int numTrees(int n) {
        int ans = ncr(2 * n, n) / (n + 1);
        return ans;
    }

    long long int ncr(int n, int r) {
        long long int ans = 1;
        for (int i = 0; i < r; i++) {
            ans *= (n - i);
            ans /= (i + 1);
        }
        return ans;
    }
};
