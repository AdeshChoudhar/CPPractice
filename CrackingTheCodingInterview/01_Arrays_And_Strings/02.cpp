//
// Problem: Given two strings, write a method to decide if one is a permutation
//          of the other.
//

#include "../../utils/utils.h"

bool solve(string& str1, string& str2) {
  bool ans = true;

  vector<int> v(26, 0);

  for (char x : str1) {
    v[x - 'a'] += 1;
  }

  for (char x : str2) {
    v[x - 'a'] -= 1;
  }

  for (int x : v) {
    if (x != 0) {
      ans = false;
      break;
    }
  }

  return ans;
}

int main() {
  string str1 = "permutation";
  string str2 = "importunate";

  cout << "INPUT(s):" << endl;
  cout << "  str1 = " << str1 << endl;
  cout << "  str2 = " << str2 << endl;

  bool ans = solve(str1, str2);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
