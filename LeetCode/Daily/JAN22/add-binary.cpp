//
// Created by adeshchoudhar on 10/01/22.
//

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1, res = 0, carry = 0;
        while (i >= 0 && j >= 0) {
            res = (a[i] - '0') + (b[j] - '0') + carry;
            carry = (int) (res > 1);
            res = res % 2;
            ans = to_string(res) + ans;
            i -= 1;
            j -= 1;
        }
        while (i >= 0) {
            res = (a[i] - '0') + carry;
            carry = (int) (res > 1);
            res = res % 2;
            ans = to_string(res) + ans;
            i -= 1;
        }
        while (j >= 0) {
            res = (b[j] - '0') + carry;
            carry = (int) (res > 1);
            res = res % 2;
            ans = to_string(res) + ans;
            j -= 1;
        }
        if (carry) {
            ans = "1" + ans;
        }
        return ans;
    }
};
