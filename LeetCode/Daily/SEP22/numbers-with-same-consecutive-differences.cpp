//
// Created by adeshchoudhar on 3/9/22.
//

class Solution {
public:
    vector<int> ans;

    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            numsSameConsecDiffUtil(n, k, i);
        }
        return ans;
    }

    void numsSameConsecDiffUtil(int n, int k, int i) {
        if (n == 1) {
            ans.push_back(i);
            return;
        }
        if (i % 10 >= k) {
            numsSameConsecDiffUtil(n - 1, k, i * 10 + (i % 10 - k));
        }
        if ((k != 0) && ((i % 10 + k) < 10)) {
            numsSameConsecDiffUtil(n - 1, k, i * 10 + (i % 10 + k));
        }
    }
};
