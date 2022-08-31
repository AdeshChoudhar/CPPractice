//
// Created by adeshchoudhar on 06/04/22.
//

class Solution {
public:
    int threeSumMulti(vector<int> &arr, int target) {
        int ans = 0, mod = 1e9 + 7;
        unordered_map<int, int> um;
        for (int i = 0, n = arr.size(); i < n; i++) {
            ans = (ans + um[target - arr[i]]) % mod;
            for (int j = 0; j < i; j++) {
                um[arr[i] + arr[j]] += 1;
            }
        }
        return ans;
    }
};
