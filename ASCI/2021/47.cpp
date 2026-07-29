//
// Problem: Reverse a String
//

#include "../../utils/utils.h"

string solve(string &s) {
  string ans(s.rbegin(), s.rend());
  return ans;
}

int main() {
  string s = "Geeks";

  cout << "INPUT(s):" << endl;
  cout << "  s = " << s << endl;

  string ans = solve(s);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
