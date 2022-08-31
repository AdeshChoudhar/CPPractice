//
// Created by adeshchoudhar on 12/7/22.
//

class Solution {
public:
    bool makesquare(vector<int> &matchsticks) {
        bool ans = false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if ((matchsticks.size() >= 4) && (sum % 4 == 0)) {
            int idx = 0;
            vector<int> sides(4, 0);
            sort(matchsticks.rbegin(), matchsticks.rend());
            ans = makesquareUtil(matchsticks, sides, idx, sum / 4);
        }
        return ans;
    }

    bool makesquareUtil(vector<int> &matchsticks, vector<int> &sides, int idx, int length) {
        if (idx == matchsticks.size()) {
            return (sides[0] == sides[1]) &&
                   (sides[1] == sides[2]) &&
                   (sides[2] == sides[3]);
        }
        for (int i = 0, j; i < 4; i++) {
            if ((sides[i] + matchsticks[idx]) > length) {
                continue;
            }
            for (j = i - 1; j >= 0; j--) {
                if (sides[i] == sides[j]) {
                    break;
                }
            }
            if (j != -1) {
                continue;
            }
            sides[i] += matchsticks[idx];
            if (makesquareUtil(matchsticks, sides, idx + 1, length)) {
                return true;
            }
            sides[i] -= matchsticks[idx];
        }
        return false;
    }
};
