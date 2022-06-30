//
// Created by adeshchoudhar on 29/06/22.
//

class Solution {
public:
    vector <vector<int>> reconstructQueue(vector <vector<int>> &people) {
        vector <vector<int>> ans;
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            return (a[0] > b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
        });
        for (vector<int> person: people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};
