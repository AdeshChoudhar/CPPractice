//
// Created by adeshchoudhar on 23/11/21.
//

class DisjointSet {
public:
    vector<int> disjoint_set;

    DisjointSet(int n) {
        disjoint_set.clear();
        disjoint_set.resize(n);
        for (int i = 0; i < n; i++) {
            disjoint_set[i] = i;
        }
    }

    void ds_union(int x, int y) {
        disjoint_set[ds_find(x)] = disjoint_set[ds_find(y)];
    }

    int ds_find(int x) {
        if (disjoint_set[x] != x) {
            disjoint_set[x] = ds_find(disjoint_set[x]);
        }
        return disjoint_set[x];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int> &nums) {
        DisjointSet ds(*max_element(nums.begin(), nums.end()) + 1);
        for (auto x: nums) {
            for (int i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    ds.ds_union(x, i);
                    ds.ds_union(x, x / i);
                }
            }
        }

        int ans = 1, tmp;
        unordered_map<int, int> mp;
        for (auto x: nums) {
            tmp = ds.ds_find(x);
            mp[tmp] += 1;
            ans = max(ans, mp[tmp]);
        }
        return ans;
    }
};
