//
// Created by adeshchoudhar on 09/06/22.
//

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        int i = 0, j = numbers.size() - 1, sum;
        while (i < j) {
            sum = numbers[i] + numbers[j];
            if (sum < target) {
                i += 1;
            } else if (sum > target) {
                j -= 1;
            } else {
                ans = {i + 1, j + 1};
                break;
            }
        }
        return ans;
    }
};
