//
// Created by adeshchoudhar on 2/8/22.
//

class Solution {
public:
    int kthSmallest(vector <vector<int>> &matrix, int k) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        priority_queue < vector < int > , vector < vector < int >>, greater<>>
        pq;
        for (int r = 0; r < min(m, k); r++) {
            pq.push({matrix[r][0], r, 0});
        }
        for (int i = 0, r, c; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            ans = top[0];
            r = top[1];
            c = top[2];
            if ((c + 1) < n) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }
        return ans;
    }
};
