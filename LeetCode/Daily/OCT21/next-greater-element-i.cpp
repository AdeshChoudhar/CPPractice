//
// Created by adeshchoudhar on 19/10/21.
//

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> s;
        unordered_map<int, int> mp;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }
            if (!s.empty()) {
                mp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            if (mp[nums1[i]]) {
                ans.push_back(mp[nums1[i]]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
