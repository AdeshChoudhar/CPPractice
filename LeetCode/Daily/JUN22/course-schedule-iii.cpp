//
// Created by adeshchoudhar on 23/06/22.
//

class Solution {
public:
    int scheduleCourse(vector <vector<int>> &courses) {
        int ans, start = 0;
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        for (int i = 0, n = courses.size(); i < n; i++) {
            start += courses[i][0];
            pq.push(courses[i][0]);
            if (start > courses[i][1]) {
                start -= pq.top();
                pq.pop();
            }
        }
        ans = pq.size();
        return ans;
    }
};
