//
// Created by adeshchoudhar on 22/8/22.
//

class Solution {
public:
    bool isPowerOfFour(int n) {
        bool ans = false;
        if (n == 0) {
            return ans;
        }
        double res = log2(n);
        ans = (ceil(res) == floor(res)) && ((((int) res) & 1) == 0);
        return ans;
    }
};
