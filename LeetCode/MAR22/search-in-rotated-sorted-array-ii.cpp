//
// Created by adeshchoudhar on 29/03/22.
//

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        bool ans = false;
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = true;
                break;
            }
            if ((nums[low] == nums[mid]) && (nums[high] == nums[mid])) {
                low += 1;
                high -= 1;
            } else if (nums[low] <= nums[mid]) {
                if ((nums[low] <= target) && (nums[mid] > target)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if ((nums[mid] < target) && (nums[high] >= target)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};
