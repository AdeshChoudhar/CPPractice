//
// Created by adeshchoudhar on 24/11/21.
//

class Solution {
public:
    vector <vector<int>> intervalIntersection(vector <vector<int>> &firstList, vector <vector<int>> &secondList) {
        int max_start, min_end;
        int first = 0, second = 0, firstLength = firstList.size(), secondLength = secondList.size();
        vector <vector<int>> ans;
        while ((first < firstLength) && (second < secondLength)) {
            max_start = max(firstList[first][0], secondList[second][0]);
            min_end = min(firstList[first][1], secondList[second][1]);
            if (max_start <= min_end) {
                ans.push_back({max_start, min_end});
            }
            if (firstList[first][1] < secondList[second][1]) {
                first += 1;
            } else {
                second += 1;
            }
        }
        return ans;
    }
};
