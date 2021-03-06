//
// Created by adeshchoudhar on 07/06/22.
//

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, k = nums1.size() - 1;
        while ((i >= 0) && (j >= 0)) {
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j -= 1;
            } else {
                nums1[k] = nums1[i];
                i -= 1;
            }
            k -= 1;
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            k -= 1;
            j -= 1;
        }
    }
};
