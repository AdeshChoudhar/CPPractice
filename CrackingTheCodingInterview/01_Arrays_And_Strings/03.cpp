//
// Problem: Write a method to replace all spaces in a string with '%20'. You may
//          assume that the string has sufficient space at the end to hold the
//          additional characters, and that you are given the "true" length of
//          the string. (Note: If implementing in Java, please use a character
//          array so that you can perform this operation in place.)
//

#include "../../utils/utils.h"

void solve(string& str, int len) {
  int r = str.length() - 1, sze = 0;

  for (int l = len - 1; l >= 0; l--) {
    if (str[l] == ' ') {
      str[r--] = '0';
      str[r--] = '2';
      str[r--] = '%';
      sze += 3;
    } else {
      str[r--] = str[l];
      sze += 1;
    }
  }

  if (r > 0) {
    for (int i = 0; i < sze; i++) {
      str[i] = str[i + r + 1];
    }

    for (int i = sze; i < str.length(); i++) {
      str[i] = ' ';
    }
  }
}

int main() {
  int len = 13;
  string str = "Mr John Smith    ";

  cout << "INPUT(s):" << endl;
  cout << "  str = " << str << endl;
  cout << "  len = " << len << endl;

  solve(str, len);
  string ans = str;

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
