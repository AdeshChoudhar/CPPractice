#include <bits/stdc++.h>

using namespace std;

template <typename T> void printVector(vector<T> &v, string s = "") {
  if (!s.empty()) {
    cout << s;
  }

  cout << "{ ";

  if (v.empty()) {
    cout << "}" << endl;
    return;
  }

  cout << v.front();

  for (int i = 1, n = v.size(); i < n; i++) {
    cout << ", " << v[i];
  }

  cout << " }" << endl;
}

template <typename T> void printMatrix(vector<vector<T>> &m, string s = "") {
    if (!s.empty()) {
        cout << s;
    }

    cout << "{" << endl;

    int len = s.length();
    string spaces(len, ' ');
    
    for (int i = 0, n = m.size(); i < n; i++) {    
        printVector<T>(m[i], spaces + "  ");
    }

    cout << spaces << "}" << endl;
}
