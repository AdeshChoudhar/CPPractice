//
// Created by adeshchoudhar on 29/9/22.
//

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> ans;
        priority_queue < pair < int, int >, vector < pair < int, int >>, greater < pair < int, int>>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(make_pair(arr[i], abs(arr[i] - x)));
        }
        for (int i = k, n = arr.size(); i < n; i++) {
            pair<int, int> t = pq.top();
            if (abs(arr[i] - x) < t.second) {
                pq.pop();
                pq.push(make_pair(arr[i], abs(arr[i] - x)));
            }
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
