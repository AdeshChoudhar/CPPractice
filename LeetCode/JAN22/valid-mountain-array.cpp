//
// Created by adeshchoudhar on 25/01/22.
//

class Solution {
public:
    bool validMountainArray(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while ((i + 1) < n && arr[i] < arr[i + 1]) {
            i += 1;
        }
        while (j > 0 && arr[j - 1] > arr[j]) {
            j -= 1;
        }
        bool ans = (i > 0) && (i == j) && (j < n - 1);
        return ans;
    }
};
