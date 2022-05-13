//
// Created by adeshchoudhar on 18/01/22.
//

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int cnt = (flowerbed.size() == 1 && flowerbed[0] == 0);
        for (int i = 0, m = flowerbed.size(); i < m; i++) {
            if (i == 0) {
                if (flowerbed[i] == 0 && (i + 1) < m && flowerbed[i + 1] == 0) {
                    cnt += 1;
                    i += 1;
                }
            } else if (i == (m - 1)) {
                if (flowerbed[i] == 0 && (i - 1) >= 0 && flowerbed[i - 1] == 0) {
                    cnt += 1;
                    i += 1;
                }
            } else {
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    cnt += 1;
                    i += 1;
                }
            }
        }
        return (cnt >= n);
    }
};
