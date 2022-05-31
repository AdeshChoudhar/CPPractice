//
// Created by adeshchoudhar on 29/05/22.
//

class Solution {
public:
    int maxProduct(vector <string> &words) {
        int ans = 0, n = words.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            for (char x: words[i]) {
                v[i] |= 1 << (x - 'a');
            }
            for (int j = 0; j < i; j++) {
                if ((v[i] & v[j]) == 0) {
                    ans = max(ans, (int) (words[i].length() * words[j].length()));
                }
            }
        }
        return ans;
    }
};
