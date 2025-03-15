#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    bool swap = false;
    for (int j = 0; j < a.size() - i - 1; j++) {
      if (a[j + 1] < a[j]) {
        int temp = a[j + 1];
        a[j + 1] = a[j];
        a[j] = temp;
        swap = true;
      }
    }
    if (!swap) {
      break;
    }
  }
}

int main() {
  vector<int> a = {1, 4, 2, 5, 5, 6, 3, 3, 4};
  bubble_sort(a);
  for (auto i : a) cout << i << " ";
  return 0;
}