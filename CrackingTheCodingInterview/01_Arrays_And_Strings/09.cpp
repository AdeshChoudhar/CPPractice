//
// Problem: Assume you have a method isSubstring which checks if one word is a
//          substring of another. Given two strings, s1 and s2, write code to
//          check if s2 is a rotation of s1 using only one call to isSubstring
//          (e.g.,"waterbottle" is a rotation of"erbottlewat").
//

#include "../../utils/utils.h"

bool solve(string& str1, string& str2) {
  bool ans = (str1.length() == str2.length());

  string str = str2 + str2;
  ans = ans && (str.find(str1) != string::npos);

  return ans;
}

int main() {
  string str1 = "waterbottle";
  string str2 = "erbottlewat";

  cout << "INPUT(s):" << endl;
  cout << "  str1 = " << str1 << endl;
  cout << "  str2 = " << str2 << endl;

  bool ans = solve(str1, str2);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << (ans ? "true" : "false") << endl;

  return 0;
}
