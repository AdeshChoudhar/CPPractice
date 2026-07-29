//
// Problem: Karatsuba Algorithm
//

#include "../../utils/utils.h"

int makeEqualLengths(string &A, string &B) {
  int res;

  int n1 = A.length(), n2 = B.length();
  if (n1 < n2) {
    A = string(n2 - n1, '0') + A;
  } else if (n2 < n1) {
    B = string(n1 - n2, '0') + B;
  }

  res = max(n1, n2);

  return res;
}

string addBitStrings(string &A, string &B) {
  string res;

  int rem = 0, n = makeEqualLengths(A, B);
  for (int i = n - 1; i >= 0; i--) {
    int sum = (A[i] - '0') + (B[i] - '0') + rem;
    res.push_back((sum % 2) + '0');
    rem = sum / 2;
  }

  if (rem == 1) {
    res.push_back('1');
  }

  reverse(res.begin(), res.end());

  return res;
}

long long solve(string A, string B) {
  long long ans = 0LL;

  int n = makeEqualLengths(A, B);
  if (n == 0) {
    return ans;
  } else if (n == 1) {
    ans = (A[0] - '0') * (B[0] - '0');
    return ans;
  }

  int fh = n / 2;
  int sh = n - fh;

  string Al = A.substr(0, fh), Ar = A.substr(fh, sh);
  string Bl = B.substr(0, fh), Br = B.substr(fh, sh);

  long long P1 = solve(Al, Bl);
  long long P2 = solve(Ar, Br);
  long long P3 = solve(addBitStrings(Al, Ar), addBitStrings(Bl, Br));

  ans = P1 * pow(2, 2 * sh) + (P3 - P1 - P2) * pow(2, sh) + P2;

  return ans;
}

int main() {
  string A = "1100";
  string B = "01";

  cout << "INPUT(s):" << endl;
  cout << "  A = " << A << endl;
  cout << "  B = " << B << endl;

  long long ans = solve(A, B);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
