//
// Created by adeshchoudhar on 13/11/21.
//

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> ans(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; i--) {
            int j = i + 1;
            bool flag = true;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                if (ans[j] > 0) {
                    j += ans[j];
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans[i] = j - i;
            }
        }
        return ans;
    }
};
