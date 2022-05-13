//
// Created by adeshchoudhar on 25/12/21.
//

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int num = 0, tmp;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = 10 * num + (s[i] - '0');
            }
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-1 * num);
                } else {
                    if (sign == '*') {
                        tmp = st.top() * num;
                    } else {
                        tmp = st.top() / num;
                    }
                    st.pop();
                    st.push(tmp);
                }
                sign = s[i];
                num = 0;
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
