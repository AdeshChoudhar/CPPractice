//
// Created by adeshchoudhar on 6/8/22.
//

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = 0;
        while (pow((minutesToTest / minutesToDie) + 1, ans) < buckets) {
            ans += 1;
        }
        return ans;
    }
};
