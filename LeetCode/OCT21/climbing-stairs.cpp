//
// Created by adeshchoudhar on 05/10/21.
//

class Solution {
public:
    unordered_map<int, int> mp = {{1, 1},
                                  {2, 2}};

    int climbStairs(int n) {
        if (mp[n]) {
            return mp[n];
        }
        mp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return mp[n];
    }
};
