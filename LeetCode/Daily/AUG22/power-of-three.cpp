//
// Created by adeshchoudhar on 24/08/22.
//

class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ans = (n > 0) && ((int) (pow(3, 19)) % n == 0);
        return ans;
    }
};
