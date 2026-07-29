//
// Problem: Factorials of large numbers
//

#include "../../utils/utils.h"

void factorialUtil(vector<int> &v, int n) {
  if ((n == 0) || (n == 1)) {
    return;
  }

  factorialUtil(v, n - 1);

  int rem = 0, sum;
  for (int i = v.size() - 1; i >= 0; i--) {
    sum = v[i] * n + rem;
    v[i] = sum % 10;
    rem = sum / 10;
  }

  while (rem > 0) {
    v.insert(v.begin(), rem % 10);
    rem = rem / 10;
  }
}

vector<int> solve(int n) {
  vector<int> ans = {1};

  factorialUtil(ans, n);

  return ans;
}

int main() {
  int n = 5;

  cout << "INPUT(s):" << endl;
  cout << "  n = " << n << endl;

  vector<int> ans = solve(n);

  cout << "OUTPUT(s):" << endl;
  printVector(ans, " ans =");

  return 0;
}
