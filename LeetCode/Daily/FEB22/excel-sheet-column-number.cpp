//
// Created by adeshchoudhar on 22/02/22.
//

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        reverse(columnTitle.begin(), columnTitle.end());
        for (int i = 0, n = columnTitle.size(); i < n; i++) {
            ans += (columnTitle[i] - 'A' + 1) * pow(26, i);
        }
        return ans;
    }
};
