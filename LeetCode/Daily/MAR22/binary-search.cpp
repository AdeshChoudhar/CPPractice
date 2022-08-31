//
// Created by adeshchoudhar on 26/03/22.
//

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int ans = -1, low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};
