//
// Created by adeshchoudhar on 13/03/22.
//

class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        stack<char> st;
        for (int i = 0, n = s.length(); i < n && ans; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    ans = false;
                } else {
                    switch (s[i]) {
                        case ')':
                            ans = (st.top() == '(');
                            break;
                        case '}':
                            ans = (st.top() == '{');
                            break;
                        case ']':
                            ans = (st.top() == '[');
                            break;
                    }
                    st.pop();
                }
            }
        }
        ans = ans && st.empty();
        return ans;
    }
};
