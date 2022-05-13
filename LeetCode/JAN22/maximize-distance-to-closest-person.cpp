//
// Created by adeshchoudhar on 16/01/22.
//

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int ans = 0, last = -1;
        for (int i = 0, n = seats.size(); i < n; i++) {
            if (seats[i] == 1) {
                ans = (last < 0) ? i : max(ans, (i - last) / 2);
                last = i;
            }
        }
        ans = max(ans, (int) seats.size() - last - 1);
        return ans;
    }
};
