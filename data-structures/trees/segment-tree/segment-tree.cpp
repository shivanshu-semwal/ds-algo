#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public:
  int* st;
  int n;
  SegmentTree(vector<int>& a) {
    n = a.size();
    st = new int[4 * a.size()];
    construct(a, 0, a.size() - 1, 0);
  }

  /* create segment tree for arr[s...e] */
  int construct(vector<int>& arr, int s, int e, int i) {
    if (s == e) return st[i] = arr[s];
    int mid = (s + e) / 2;
    return st[i] = construct(arr, s, mid, i * 2 + 1) +
                   construct(arr, mid + 1, e, 2 * i + 2);
  }

  int query(int s, int e, int qs, int qe, int i) {
    if (qs <= s && e <= qe) return st[i];
    if (qs > e || qe < s) return 0;
    int mid = (s + e) / 2;
    return query(s, mid, qs, qe, 2 * i + 1) +
           query(mid + 1, e, qs, qe, 2 * i + 2);
  }

  void updateUtil(int s, int e, int i0, int diff, int i) {
    if (i0 < s || i0 > e) return;
    st[i] += diff;
    if (s != e) {
      int mid = (s + e) / 2;
      updateUtil(s, mid, i0, diff, 2 * i + 1);
      updateUtil(mid + 1, e, i0, diff, 2 * i + 2);
    }
  }

  void update(int i0, int diff) {
    if (i0 < 0 || i0 > n - 1) return;
    updateUtil(0, n - 1, i0, diff, 0);
  }
};

int main() {
  vector<int> a = {1, 3, 5, 7, 9, 11};
  SegmentTree s(a);
  cout << s.query(0, a.size() - 1, 1, 3, 0) << endl;
  s.update(1, 7);
  cout << s.query(0, a.size() - 1, 1, 3, 0) << endl;
  return 0;
}