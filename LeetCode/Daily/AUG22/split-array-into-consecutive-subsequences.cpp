//
// Created by adeshchoudhar on 19/8/22.
//

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        bool ans = true;
        unordered_map<int, int> left, done;
        for (int num: nums) {
            left[num] += 1;
        }
        for (int num: nums) {
            if (left[num] == 0) {
                continue;
            }
            left[num] -= 1;
            if (done[num - 1] > 0) {
                done[num - 1] -= 1;
                done[num] += 1;
            } else if ((left[num + 1] > 0) && (left[num + 2] > 0)) {
                left[num + 1] -= 1;
                left[num + 2] -= 1;
                done[num + 2] += 1;
            } else {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
