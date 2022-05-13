//
// Created by adeshchoudhar on 30/10/21.
//

class Solution {
public:
    string longestDupSubstring(string s) {
        string_view sv;
        unordered_set <string_view> us;

        int l = 1, r = s.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            bool flag = false;
            for (int i = 0; i < s.size() - mid + 1; i++) {
                const auto[it, inserted] = us.emplace(s.data() + i, mid);
                if (!inserted) {
                    flag = true;
                    sv = *it;
                    break;
                }
            }
            if (flag) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            us.clear();
        }

        string ans = string(sv.begin(), sv.end());
        return ans;
    }
};
