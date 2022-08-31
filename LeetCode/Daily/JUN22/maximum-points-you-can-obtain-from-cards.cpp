//
// Created by adeshchoudhar on 26/06/22.
//

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int ans = 0, n = cardPoints.size(), sum, cnt;
        sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        cnt = accumulate(cardPoints.begin(), cardPoints.begin() + (n - k), 0);
        ans = max(ans, sum - cnt);
        for (int i = (n - k); i < n; i++) {
            cnt += (cardPoints[i] - cardPoints[i - (n - k)]);
            ans = max(ans, sum - cnt);
        }
        return ans;
    }
};
