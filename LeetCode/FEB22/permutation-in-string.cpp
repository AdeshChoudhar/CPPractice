//
// Created by adeshchoudhar on 11/02/22.
//

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool ans = false;
        int m = s1.length(), n = s2.length();
        if (m > n) {
            return ans;
        }
        vector<int> v(26, 0), zero(26, 0);
        for (int i = 0; i < m; i++) {
            v[(int) (s1[i] - 'a')] += 1;
            v[(int) (s2[i] - 'a')] -= 1;
        }
        if (v == zero) {
            return true;
        }
        for (int i = m; i < n; i++) {
            v[(int) (s2[i - m] - 'a')] += 1;
            v[(int) (s2[i] - 'a')] -= 1;
            if (v == zero) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};
