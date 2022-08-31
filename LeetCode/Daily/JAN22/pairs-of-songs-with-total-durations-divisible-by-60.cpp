//
// Created by adeshchoudhar on 02/01/22.
//

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int ans = 0;
        vector<int> v(60);
        for (int t: time) {
            ans += v[(60 - t % 60) % 60];
            v[t % 60] += 1;
        }
        return ans;
    }
};
