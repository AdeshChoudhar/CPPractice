//
// Created by adeshchoudhar on 10/10/21.
//

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left = left >> 1;
            right = right >> 1;
            cnt += 1;
        }
        int ans = left << cnt;
        return ans;
    }
};
