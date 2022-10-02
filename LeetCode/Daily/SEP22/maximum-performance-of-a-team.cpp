//
// Created by adeshchoudhar on 11/9/22.
//

class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        int ans, mod = (int) (1e9 + 7);
        vector <pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = make_pair(efficiency[i], speed[i]);
        }
        sort(v.rbegin(), v.rend());
        long long sum = 0, cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (pair<int, int> p: v) {
            pq.push(p.second);
            sum += p.second;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            cnt = max(cnt, sum * p.first);
        }
        ans = cnt % mod;
        return ans;
    }
};
