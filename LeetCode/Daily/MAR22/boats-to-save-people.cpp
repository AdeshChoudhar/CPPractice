//
// Created by adeshchoudhar on 24/03/22.
//

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i += 1;
                j -= 1;
            } else {
                j -= 1;
            }
            ans += 1;
        }
        return ans;
    }
};
