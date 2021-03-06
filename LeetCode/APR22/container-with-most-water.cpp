//
// Created by adeshchoudhar on 05/04/22.
//

class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l += 1;
            } else if (height[l] > height[r]) {
                r -= 1;
            } else {
                l += 1;
                r -= 1;
            }
        }
        return ans;
    }
};
