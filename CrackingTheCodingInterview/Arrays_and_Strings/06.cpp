//
// Problem: Implement a method to perform basic string compression using the
//          counts of repeated characters. For example, the string aabcccccaaa
//          would become a2blc5a3. If the "compressed" string would not become
//          smaller than the original string, your method should return the
//          original string. You can assume the string has only uppercase and
//          lowercase letters (a - z).
//

#include "../../utils/utils.h"

string solve(string& str) {
  string ans;

  int cnt = 1;
  char chr = str[0];

  for (int i = 1, n = str.length(); i < n; i++) {
    if (str[i] == str[i - 1]) {
      cnt += 1;
    } else {
      ans.push_back(chr);
      ans += to_string(cnt);
      cnt = 1;
      chr = str[i];
    }
  }

  ans.push_back(chr);
  ans += to_string(cnt);

  if (str.size() <= ans.size()) {
    ans = str;
  }

  return ans;
}

int main() {
  string str = "aabcccccaaa";

  cout << "INPUT(s):" << endl;
  cout << "  str = " << str << endl;

  string ans = solve(str);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
