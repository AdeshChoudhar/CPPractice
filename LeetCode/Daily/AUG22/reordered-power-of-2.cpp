//
// Created by adeshchoudhar on 26/8/22.
//

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        bool ans = false;
        int len = 0;
        unordered_map<int, int> um1;
        for (int i = n; i != 0; i /= 10, len += 1) {
            um1[i % 10] += 1;
        }
        unordered_map<int, vector<int>> um = {
                {1, {1,         2,         4,       8}},
                {2, {16,        32,        64}},
                {3, {128,       256,       512}},
                {4, {1024,      2048,      4096,    8192}},
                {5, {16384,     32768,     65536}},
                {6, {131072,    262144,    524288}},
                {7, {1048576,   2097152,   4194304, 8388608}},
                {8, {16777216,  33554432,  67108864}},
                {9, {134217728, 268435456, 536870912}}
        };
        for (int x: um[len]) {
            unordered_map<int, int> um2;
            for (int i = x; i != 0; i /= 10) {
                um2[i % 10] += 1;
            }
            if (um1 == um2) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};
