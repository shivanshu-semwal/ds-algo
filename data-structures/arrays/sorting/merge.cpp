#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int start, int mid, int end) {
  vector<int> left(a.begin() + start, a.begin() + mid + 1);
  vector<int> right(a.begin() + mid + 1, a.begin() + end + 1);
  int i = 0, j = 0, k = start;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j])
      a[k++] = left[i++];
    else
      a[k++] = right[j++];
  }
  while (i < left.size()) a[k++] = left[i++];
  while (j < right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int start, int end) {
  if (start >= end) return;
  int mid = start + (end - start) / 2;
  mergeSort(a, start, mid);
  mergeSort(a, mid + 1, end);
  merge(a, start, mid, end);
}

int main() {
  vector<int> a = {1, 4, 2, 5, 5, 6, 3, 3, 4};
  mergeSort(a, 0, a.size() - 1);
  for (auto i : a) cout << i << " ";
  return 0;
}