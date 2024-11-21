#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& a, int start, int end) {
  int pivot = a[end]; // chossing pivot
  int i = start - 1;  // smaller elements counter
  for (int j = start; j <= end; j++) {
    if (a[j] < pivot) swap(a[++i], a[j]);
  }
  swap(a[++i], a[end]);
  return i;
}

void quick_sort(vector<int>& a, int start, int end) {
  if (start >= end) return;
  int p = partition(a, start, end);
  quick_sort(a, start, p - 1);
  quick_sort(a, p + 1, end);
}

int main() {
  vector<int> a = {1, 4, 2, 5, 5, 6, 3, 3, 4};
  quick_sort(a, 0, a.size() - 1);
  for (auto i : a) cout << i << " ";
  return 0;
}