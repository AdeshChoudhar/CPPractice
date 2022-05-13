//
// Created by adeshchoudhar on 18/03/22.
//

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(26, 0);
        vector<int> b(26, false);
        for (int i = 0, n = s.length(); i < n; i++) {
            v[s[i] - 'a'] = i;
        }
        int x;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (b[x]) {
                continue;
            }
            while (st.size() > 0 && st.top() > s[i] && i < v[st.top() - 'a']) {
                b[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            b[x] = true;
        }
        string ans = "";
        while (st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
