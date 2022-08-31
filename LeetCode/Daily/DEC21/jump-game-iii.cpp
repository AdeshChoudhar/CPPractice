//
// Created by adeshchoudhar on 09/12/21.
//

class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(arr.size());
        visited[start] = true;
        bool ans = false;
        int ind, left_ind, right_ind;
        while (!q.empty() && !ans) {
            for (int i = 0, n = q.size(); i < n; i++) {
                ind = q.front();
                q.pop();
                if (arr[ind] == 0) {
                    ans = true;
                    break;
                }
                left_ind = ind - arr[ind];
                right_ind = ind + arr[ind];
                if (((left_ind > -1) && (left_ind < arr.size())) && !visited[left_ind]) {
                    if (arr[left_ind] == 0) {
                        ans = true;
                        break;
                    } else {
                        q.push(left_ind);
                        visited[left_ind] = true;
                    }
                }
                if (((right_ind > -1) && (right_ind < arr.size())) && !visited[right_ind]) {
                    if (arr[right_ind] == 0) {
                        ans = true;
                        break;
                    } else {
                        q.push(right_ind);
                        visited[right_ind] = true;
                    }
                }
            }
        }
        return ans;
    }
};
