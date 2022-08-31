//
// Created by adeshchoudhar on 06/05/22.
//

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans = "";
        stack <pair<char, int>> st;
        for (auto x: s) {
            if (!st.empty() && st.top().first == x) {
                st.top().second += 1;
            } else {
                st.push(make_pair(x, 1));
            }
            if (st.top().second == k) {
                st.pop();
            }
        }
        pair<char, int> x;
        for (int i = 0, n = st.size(); i < n; i++) {
            x = st.top();
            st.pop();
            for (int j = 0, n = x.second; j < n; j++) {
                ans.push_back(x.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
