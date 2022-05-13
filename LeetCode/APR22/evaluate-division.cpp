//
// Created by adeshchoudhar on 30/04/22.
//

class Solution {
public:
    unordered_map <string, vector<pair < string, double>>>
    um;
    unordered_set <string> us;

    vector<double>
    calcEquation(vector <vector<string>> &equations, vector<double> &values, vector <vector<string>> &queries) {
        vector<double> ans;
        string a, b;
        double c;
        for (int i = 0, n = equations.size(); i < n; i++) {
            a = equations[i][0];
            b = equations[i][1];
            c = values[i];
            um[a].push_back({b, c});
            um[b].push_back({a, (double) (1 / c)});
        }
        for (auto query: queries) {
            us.clear();
            ans.push_back(calcEquationUtil(query[0], query[1]));
        }
        return ans;
    }

    double calcEquationUtil(string src, string dst) {
        double res;
        if (um.find(src) == um.end()) {
            return -1;
        }
        if (src == dst) {
            return 1;
        }
        for (auto x: um[src]) {
            if (us.count(x.first) == 0) {
                us.insert(x.first);
                res = calcEquationUtil(x.first, dst);
                if (res != -1) {
                    res *= x.second;
                    return res;
                }
            }
        }
        return -1;
    }
};
