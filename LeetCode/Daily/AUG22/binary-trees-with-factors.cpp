//
// Created by adeshchoudhar on 9/8/22.
//

class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        int ans = 0, mod = (int) (1e9 + 7);
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> um;
        for (int i = 0, n = arr.size(); i < n; i++) {
            um[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if ((arr[i] % arr[j]) == 0) {
                    um[arr[i]] = (um[arr[i]] + um[arr[j]] * um[arr[i] / arr[j]]) % mod;
                }
            }
            ans = (ans + um[arr[i]]) % mod;
        }
        return ans;
    }
};
