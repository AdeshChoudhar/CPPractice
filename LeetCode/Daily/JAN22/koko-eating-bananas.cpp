//
// Created by adeshchoudhar on 20/01/22.
//

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid, hours;
        while (low < high) {
            mid = low + (high - low) / 2;
            hours = 0;
            for (int pile: piles) {
                hours += (pile + mid - 1) / mid;
            }
            if (hours > h) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int ans = low;
        return ans;
    }
};
