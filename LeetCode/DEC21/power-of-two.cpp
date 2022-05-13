//
// Created by adeshchoudhar on 21/12/21.
//

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        bool ans = (log2(abs(n)) - (int) (log2(abs(n)))) == 0;
        return ans;
    }
};
