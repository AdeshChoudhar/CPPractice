//
// Created by adeshchoudhar on 14/06/22.
//

class Solution {
public:
    int minDistance(string word1, string word2) {
        int ans, l1 = word1.length(), l2 = word2.length();
        if (l1 < l2) {
            swap(word1, word2);
            swap(l1, l2);
        }
        vector <vector<int>> dp(2, vector<int>(l2 + 1));
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                if ((i == 0) || (j == 0)) {
                    dp[i & 1][j] = (i + j);
                } else {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i & 1][j] = dp[(i - 1) & 1][j - 1];
                    } else {
                        dp[i & 1][j] = 1 + min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
                    }
                }
            }
        }
        ans = dp[l1 & 1][l2];
        return ans;
    }
};
