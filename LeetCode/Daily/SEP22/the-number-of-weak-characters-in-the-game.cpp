//
// Created by adeshchoudhar on 9/9/22.
//

class Solution {
public:
    int numberOfWeakCharacters(vector <vector<int>> &properties) {
        int ans = 0, mxm = INT_MIN;
        sort(properties.begin(), properties.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        for (int i = properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < mxm) {
                ans += 1;
            }
            mxm = max(mxm, properties[i][1]);
        }
        return ans;
    }
};
