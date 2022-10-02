//
// Created by adeshchoudhar on 21/9/22.
//

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector <vector<int>> &queries) {
        vector<int> ans;
        int sum = 0;
        for (int num: nums) {
            if ((num & 1) == 0) {
                sum += num;
            }
        }
        for (vector<int> query: queries) {
            if ((nums[query[1]] & 1) == 0) {
                if ((query[0] & 1) == 0) {
                    sum += query[0];
                } else {
                    sum -= nums[query[1]];
                }
                nums[query[1]] += query[0];
            } else {
                nums[query[1]] += query[0];
                if ((query[0] & 1) != 0) {
                    sum += nums[query[1]];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
