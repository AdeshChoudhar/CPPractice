//
// Created by adeshchoudhar on 09/01/22.
//

class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> xy = {0, 0};
        pair<int, int> d = {0, 1};
        for (auto instruction: instructions) {
            if (instruction == 'G') {
                xy = {xy.first + d.first, xy.second + d.second};
            } else if (instruction == 'L') {
                d = {-1 * d.second, d.first};
            } else if (instruction == 'R') {
                d = {d.second, -1 * d.first};
            }
        }
        bool ans = (xy == make_pair(0, 0)) || (d != make_pair(0, 1));
        return ans;
    }
};
