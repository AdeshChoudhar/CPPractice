//
// Created by adeshchoudhar on 18/12/21.
//

class Solution {
public:
    int atMostNGivenDigitSet(vector <string> &digits, int n) {
        int ans = 0;
        string number = to_string(n);
        for (int i = 1; i < number.size(); i++) {
            ans += pow(digits.size(), i);
        }

        for (int i = 0; i < number.size(); i++) {
            bool flag = false;
            for (auto digit: digits) {
                if (digit[0] < number[i]) {
                    ans += pow(digits.size(), number.size() - i - 1);
                } else if (digit[0] == number[i]) {
                    flag = true;
                }
            }
            if (!flag) {
                return ans;
            }
        }
        ans += 1;
        return ans;
    }
};
