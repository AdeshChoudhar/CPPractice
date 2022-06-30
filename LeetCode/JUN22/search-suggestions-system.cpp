//
// Created by adeshchoudhar on 19/06/22.
//

class Solution {
public:
    vector <vector<string>> suggestedProducts(vector <string> &products, string searchWord) {
        vector <vector<string>> ans;
        auto it = products.begin();
        sort(it, products.end());
        string s, t;
        for (char c: searchWord) {
            s.push_back(c);
            vector <string> v;
            it = lower_bound(it, products.end(), s);
            for (int i = 0; (i < 3) && ((it + i) != products.end()); i++) {
                t = *(it + i);
                if (t.find(s) != string::npos) {
                    break;
                }
                v.push_back(t);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
