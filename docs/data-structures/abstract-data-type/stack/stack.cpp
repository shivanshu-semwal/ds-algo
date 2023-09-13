#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
  vector<int> storage;

public:
  Stack() : storage(vector<int>()) {}
  bool empty() { return storage.empty(); }
  void push(int val) {
    storage.push_back(val);
  }
  void pop() {
    storage.pop_back();
  }
  int top() {
    return storage.back();
  }
};

int main() {
  vector<int> aa = {10, 11, 12, 13, 14, 15};
  Stack st;
  for (int i : aa) st.push(i);

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}