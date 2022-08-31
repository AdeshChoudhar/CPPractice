//
// Created by adeshchoudhar on 31/01/22.
//

class Solution {
public:
    int maximumWealth(vector <vector<int>> &accounts) {
        int ans = 0, total;
        for (vector<int> account: accounts) {
            total = 0;
            for (int money: account) {
                total += money;
            }
            ans = max(ans, total);
        }
        return ans;
    }
};
