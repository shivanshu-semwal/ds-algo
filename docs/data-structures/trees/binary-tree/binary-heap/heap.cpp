#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
  vector<int> storage;

  static void heapifyHelper(vector<int>& a, int idx) {
    int n = a.size();
    int largest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != idx) {
      swap(a[idx], a[largest]);
      heapifyHelper(a, largest);
    }
  }

public:
  Heap() {
    storage = vector<int>();
  }

  Heap(vector<int> arr) {
    storage = vector<int>(arr);
    Heap::heapify(this->storage);
  }

  void push(int val) {
    storage.push_back(val);
    int i = storage.size() - 1;
    while (i > 0) {
      int parent = (i - 1) / 2;
      if (storage[parent] < storage[i]) {
        swap(storage[parent], storage[i]);
        i = parent;
      } else {
        break;
      }
    }
  }

  int top() {
    // undefined behaviour if storage is empty
    return storage.front();
  }

  void pop() {
    if (storage.empty()) return;
    storage.front() = storage.back();
    storage.pop_back();
    Heap::heapifyHelper(storage, 0);
  }

  inline bool empty() {
    return storage.empty();
  }

  static void heapify(vector<int>& a) {
    int n = a.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
      heapifyHelper(a, i);
    }
  }

  static void sort(vector<int>& arr) {
    Heap h(arr);
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = h.top();
      h.pop();
    }
  }
};

int main() {
  vector<int> a = {1, 2, 54, 23, 21, 32, 31};
  Heap h(a);

  for (int i = 0; i < a.size(); i++) {
    cout << h.top() << " ";
    h.pop();
  }
  cout << "\n";

  Heap::sort(a);
  for (auto i : a) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}