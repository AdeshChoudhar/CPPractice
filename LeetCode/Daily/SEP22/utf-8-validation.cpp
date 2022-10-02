//
// Created by adeshchoudhar on 13/9/22.
//

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        bool ans;
        int cnt = 0;
        for (int d: data) {
            if (cnt == 0) {
                if ((d >> 5) == 0b110) {
                    cnt = 1;
                } else if ((d >> 4) == 0b1110) {
                    cnt = 2;
                } else if ((d >> 3) == 0b11110) {
                    cnt = 3;
                } else if ((d >> 7)) {
                    return ans;
                }
            } else {
                if ((d >> 6) != 0b10) {
                    return ans;
                }
                cnt -= 1;
            }
        }
        ans = (cnt == 0);
        return ans;
    }
};
