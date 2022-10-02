//
// Created by adeshchoudhar on 26/9/22.
//

class Solution {
public:
    vector<char> parent;

    bool equationsPossible(vector <string> &equations) {
        bool ans = true;
        int n = 26;
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (string equation: equations) {
            if (equation[1] == '=') {
                char a = findParent(equation.front() - 'a');
                char b = findParent(equation.back() - 'a');
                if (a != b) {
                    parent[b] = a;
                }
            }
        }
        for (string equation: equations) {
            if (equation[1] == '!') {
                char a = findParent(equation.front() - 'a');
                char b = findParent(equation.back() - 'a');
                if (a == b) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }

    char findParent(char x) {
        return (parent[x] == x) ? x : findParent(parent[x]);
    }
};
