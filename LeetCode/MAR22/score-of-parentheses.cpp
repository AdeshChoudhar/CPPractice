//
// Created by adeshchoudhar on 17/03/22.
//

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, depth = 0;
        char prev = '(';
        for (auto x: s) {
            if (x == '(') {
                depth += 1;
            } else {
                depth -= 1;
                if (prev == '(') {
                    ans += pow(2, depth);
                }
            }
            prev = x;
        }
        return ans;
    }
};
