//
// Created by adeshchoudhar on 13/01/22.
//

class Solution {
public:
    int findMinArrowShots(vector <vector<int>> &points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int ans = 1, end = INT_MAX;
        for (auto point: points) {
            if (point[0] > end) {
                ans += 1;
                end = point[1];
            } else {
                end = min(end, point[1]);
            }
        }
        return ans;
    }
};
