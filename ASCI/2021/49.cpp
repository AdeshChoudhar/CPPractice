//
// Problem: String Duplicates Removal
//

#include "../../utils/utils.h"

string solve(string &s) {
  string ans;

  unordered_map<char, int> um;
  for (auto x : s) {
    if (um[x] == 0) {
      ans.push_back(x);
    }

    um[x] += 1;
  }

  return ans;
}

int main() {
  string s = "geEksforGEeks";

  cout << "INPUT(s):" << endl;
  cout << "  s = " << s << endl;

  string ans = solve(s);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
