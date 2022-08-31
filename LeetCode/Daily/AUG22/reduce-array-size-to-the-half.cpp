//
// Created by adeshchoudhar on 18/8/22.
//

class Solution {
public:
    int minSetSize(vector<int> &arr) {
        int ans = 0, sum = 0, n = arr.size();
        map<int, int> mp;
        for (int x: arr) {
            mp[x] += 1;
        }
        vector<int> v;
        for (auto x: mp) {
            v.push_back(x.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (auto x: v) {
            ans += 1;
            sum += x;
            if (sum >= (n / 2)) {
                break;
            }
        }
        return ans;
    }
};
