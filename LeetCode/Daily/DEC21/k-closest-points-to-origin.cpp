//
// Created by adeshchoudhar on 26/12/21.
//

class Solution {
public:
    vector <vector<int>> kClosest(vector <vector<int>> &points, int k) {
        multimap<double, vector<int>> mmp;
        double euclidean_distance;
        for (auto point: points) {
            euclidean_distance = sqrt(pow(point[0], 2) + pow(point[1], 2));
            mmp.insert(make_pair(euclidean_distance, point));
        }
        multimap<double, vector<int>> mp(mmp.begin(), mmp.end());
        vector <vector<int>> ans;
        int cnt = 0;
        for (auto x: mp) {
            if (cnt == k) {
                break;
            }
            ans.push_back(x.second);
            cnt += 1;
        }
        return ans;
    }
};
