//
// Created by adeshchoudhar on 08/02/22.
//

class Solution {
public:
    int addDigits(int num) {
        int ans = (num == 0) ? 0 : (1 + (num - 1) % 9);
        return ans;
    }
};
