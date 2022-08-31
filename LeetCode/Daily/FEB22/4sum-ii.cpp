//
// Created by adeshchoudhar on 03/02/22.
//

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> um;
        for (int num1: nums1) {
            for (int num2: nums2) {
                um[num1 + num2] += 1;
            }
        }
        int ans = 0;
        for (int num3: nums3) {
            for (int num4: nums4) {
                auto it = um.find(-num3 - num4);
                if (it != um.end()) {
                    ans += it->second;
                }
            }
        }
        return ans;
    }
};
