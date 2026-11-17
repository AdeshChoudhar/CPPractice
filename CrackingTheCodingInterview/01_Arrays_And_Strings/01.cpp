//
// Problem: Implement an algorithm to determine if a string has all unique
//          characters. What if you cannot use additional data structures?
//

#include "../../utils/utils.h"

bool solve(string& str) {
  bool ans = true;

  sort(str.begin(), str.end());

  for (int i = 0, n = str.length(); i < (n - 1); i++) {
    if (str[i] == str[i + 1]) {
      ans = false;
      return ans;
    }
  }

  return ans;
}

int main() {
  string str = "unique";

  cout << "INPUT(s):" << endl;
  cout << "  str = " << str << endl;

  bool ans = solve(str);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
