//
// Created by adeshchoudhar on 18/02/22.
//

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char n: num) {
            while (ans.length() && ans.back() > n && k) {
                ans.pop_back();
                k -= 1;
            }
            if (ans.length() || n != '0') {
                ans.push_back(n);
            }
        }
        while (ans.length() && k) {
            ans.pop_back();
            k -= 1;
        }
        if (ans.empty()) {
            ans.push_back('0');
        }
        return ans;
    }
};
