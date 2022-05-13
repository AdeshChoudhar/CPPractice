//
// Created by adeshchoudhar on 19/12/21.
//

class Solution {
public:
    int ind;

    string decodeString(string s) {
        ind = 0;
        string ans = decodeStringUtil(s);
        return ans;
    }

    string decodeStringUtil(string s) {
        string res = "";
        while ((ind < s.length()) && (s[ind] != ']')) {
            if (!isdigit(s[ind])) {
                res += s[ind];
                ind += 1;
            } else {
                int num = 0;
                while ((ind < s.length()) && isdigit(s[ind])) {
                    num = num * 10 + (s[ind] - '0');
                    ind += 1;
                }
                ind += 1;
                string tmp = decodeStringUtil(s);
                ind += 1;
                for (int i = 0; i < num; i++) {
                    res += tmp;
                }
            }
        }
        return res;
    }
};
