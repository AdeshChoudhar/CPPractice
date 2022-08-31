//
// Created by adeshchoudhar on 27/05/22.
//

class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num) {
            if (num & 1) {
                num -= 1;
            } else {
                num >>= 1;
            }
            ans += 1;
        }
        return ans;
    }
};
