//
// Created by adeshchoudhar on 15/03/22.
//

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int> st;
        for (int i = 0, n = s.length(); i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*';
                }
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        for (auto x: s) {
            if (x != '*') {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
