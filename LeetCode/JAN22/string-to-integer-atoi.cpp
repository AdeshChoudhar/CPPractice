//
// Created by adeshchoudhar on 14/01/22.
//

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        for (; i < n && isspace(s[i]); i++);
        int sign = 1;
        if (i < n) {
            if (s[i] == '+' || s[i] == '-') {
                sign = (s[i] == '-') ? -1 : 1;
                i += 1;
            }
        }
        bool flag = false;
        string digits = "";
        for (; i < n && isdigit(s[i]); i++) {
            if (s[i] == '0') {
                if (flag) {
                    digits.push_back(s[i]);
                }
            } else {
                digits.push_back(s[i]);
                flag = true;
            }
        }
        if (digits.empty()) {
            return 0;
        }
        long long res = 0;
        for (int j = 0, m = min((int) digits.length(), 18); j < m; j++) {
            res *= 10;
            res += (digits[j] - '0');
        }
        int ans;
        if (sign == 1) {
            if (res > INT_MAX) {
                ans = INT_MAX;
            } else {
                ans = res;
            }
        } else {
            res *= -1;
            if (res < INT_MIN) {
                ans = INT_MIN;
            } else {
                ans = res;
            }
        }
        return ans;
    }
};
