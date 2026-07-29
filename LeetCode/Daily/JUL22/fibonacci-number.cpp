//
// Created by adeshchoudhar on 06/07/22.
//

class Solution {
public:
    int fib(int n) {
        int ans = n;
        if (n <= 1) {
            return ans;
        }
        int a = 0, b = 1, c = 1;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        ans = c;
        return ans;
    }
};
