//
// Created by adeshchoudhar on 09/04/22.
//

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> ans;
        unordered_map<int, int> um;
        for (int num: nums) {
            um[num] += 1;
        }
        multimap<int, int> mm;
        for (auto x: um) {
            mm.insert(make_pair(x.second, x.first));
        }
        for (auto it = mm.rbegin(); it != mm.rend() && k; it++, k--) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
