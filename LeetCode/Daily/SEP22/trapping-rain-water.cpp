//
// Created by adeshchoudhar on 18/9/22.
//

class Solution {
public:
    int trap(vector<int> &height) {
        int ans = 0;
        for (int i = 0, j = height.size() - 1, mxm = 0, mnm = 0; i <= j;) {
            mnm = min(height[i], height[j]);
            mxm = max(mxm, mnm);
            ans += (mxm - mnm);
            if (height[i] < height[j]) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        return ans;
    }
};
