//
// Created by adeshchoudhar on 29/01/22.
//

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int ans = 0, l, b;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0, n = heights.size(); i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                l = heights[s.top()];
                s.pop();
                b = s.empty() ? -1 : s.top();
                ans = max(ans, l * (i - b - 1));
            }
            s.push(i);
        }
        return ans;
    }
};
