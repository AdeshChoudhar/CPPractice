//
// Created by adeshchoudhar on 27/10/21.
//

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int red = 0, white = 0, blue = nums.size() - 1;
        while (white <= blue) {
            if (nums[white] == 0) {
                swap(nums[white], nums[red]);
                white += 1;
                red += 1;
            } else if (nums[white] == 2) {
                swap(nums[white], nums[blue]);
                blue -= 1;
            } else {
                white += 1;
            }
        }
    }
};
