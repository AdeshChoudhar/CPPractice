//
// Created by adeshchoudhar on 12/9/22.
//

class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int ans = 0;
        sort(tokens.begin(), tokens.end());
        for (int i = 0, j = tokens.size() - 1, p = 0; i <= j;) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                i += 1;
                p += 1;
                ans = max(ans, p);
            } else if (p > 0) {
                p -= 1;
                power += tokens[j];
                j -= 1;
            } else {
                break;
            }
        }
        return ans;
    }
};
