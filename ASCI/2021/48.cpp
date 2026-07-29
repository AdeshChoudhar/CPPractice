//
// Problem: Palindrome String
//

#include "../../utils/utils.h"

bool solve(string &s) {
  bool ans = true;

  for (int i = 0, n = s.size(); i < (n / 2); i++) {
    if (s[i] != s[n - 1 - i]) {
      ans = false;
      return ans;
    }
  }

  return ans;
}

int main() {
  string s = "abba";

  cout << "INPUT(s):" << endl;
  cout << "  s = " << s << endl;

  bool ans = solve(s);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
