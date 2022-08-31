//
// Created by adeshchoudhar on 1/7/22.
//

class Solution {
public:
    int maximumUnits(vector <vector<int>> &boxTypes, int truckSize) {
        int ans = 0, box;
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) {
            return (a[1] > b[1]);
        });
        for (int i = 0, n = boxTypes.size(); (i < n) && (truckSize != 0); i++) {
            box = min(boxTypes[i][0], truckSize);
            truckSize -= box;
            ans += box * boxTypes[i][1];
        }
        return ans;
    }
};
