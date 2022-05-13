//
// Created by adeshchoudhar on 16/03/22.
//

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> st;
        int i = 0;
        for (int x: pushed) {
            st.push(x);
            while (st.size() && st.top() == popped[i]) {
                st.pop();
                i += 1;
            }
        }
        bool ans = (st.size() == 0);
        return ans;
    }
};
