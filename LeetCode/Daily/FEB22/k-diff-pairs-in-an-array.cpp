//
// Created by adeshchoudhar on 09/02/22.
//

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        unordered_set<int> s;
        unordered_map<int, int> um;
        for (int num: nums) {
            if (um.find(num - k) != um.end()) {
                s.insert(num - k);
            }
            if (um.find(num + k) != um.end()) {
                s.insert(num);
            }
            um[num] = 1;
        }
        int ans = s.size();
        return ans;
    }
};
