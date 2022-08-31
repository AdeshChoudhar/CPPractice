//
// Created by adeshchoudhar on 06/12/21.
//

class Solution {
public:
    int minCostToMoveChips(vector<int> &position) {
        int odd = 0, even = 0;
        for (int x: position) {
            if (x % 2) {
                odd += 1;
            } else {
                even += 1;
            }
        }
        int ans = min(odd, even);
        return ans;
    }
};
