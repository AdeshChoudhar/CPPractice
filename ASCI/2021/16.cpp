//
// Problem: Count Inversions
//

#include "../../utils/utils.h"

class SegmentTree {
public:
  vector<int> seg;

  SegmentTree(int n) { seg.resize(4 * n + 1); }

  void build(int idx, vector<int> &arr, int low, int hih) {
    if (low == hih) {
      seg[idx] = arr[low];
      return;
    }

    int mid = low + (hih - low) / 2;
    build(2 * idx + 1, arr, low, mid);
    build(2 * idx + 2, arr, mid + 1, hih);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
  }

  int query(int idx, int low, int hih, int l, int r) {
    int res = 0;
    if ((l <= low) && (hih <= r)) {
      res = seg[idx];
      return res;
    }

    if ((l > hih) || (low > r)) {
      return res;
    }

    int mid = low + (hih - low) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, hih, l, r);
    res = left + right;

    return res;
  }

  void update(int idx, int low, int hih, int cur, int val) {
    if (low == hih) {
      seg[idx] += val;
      return;
    }

    int mid = low + (hih - low) / 2;
    if (cur <= mid) {
      update(2 * idx + 1, low, mid, cur, val);
    } else {
      update(2 * idx + 2, mid + 1, hih, cur, val);
    }

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
  }
};

int solve(vector<int> &arr) {
  int ans = 0;
  int n = arr.size(), mxm = 1 + *max_element(arr.begin(), arr.end());

  vector<int> fre(mxm, 0);
  for (auto x : arr) {
    fre[x] += 1;
  }

  SegmentTree st(mxm);
  st.build(0, fre, 0, mxm - 1);

  for (int i = 0; i < n; i++) {
    fre[arr[i]] -= 1;
    st.update(0, 0, mxm - 1, arr[i], -1);
    ans += st.query(0, 0, mxm - 1, 1, arr[i] - 1);
  }

  return ans;
}

int main() {
  vector<int> arr = {2, 4, 1, 3, 5};

  cout << "INPUT(s):" << endl;
  printVector(arr, "  arr = ");

  int ans = solve(arr);

  cout << "OUTPUT(s):" << endl;
  cout << "  ans = " << ans << endl;

  return 0;
}
