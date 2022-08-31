//
// Created by adeshchoudhar on 07/05/22.
//

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        bool ans = false;
        stack<int> st;
        int mini = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < mini) {
                ans = true;
                break;
            } else {
                while (!st.empty() && nums[i] > st.top()) {
                    mini = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return ans;
    }
};
