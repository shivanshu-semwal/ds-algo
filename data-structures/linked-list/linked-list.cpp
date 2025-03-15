#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node(int data, Node* next) : data(data), next(next) {}
  Node(int data) : data(data), next(nullptr) {}
};

int main() {
  vector<int> a = {1, 2, 3, 4, 5};
  Node* head = new Node(a[0]);

  Node* t = head;
  for (int i = 1; i < a.size(); i++) {
    t->next = new Node(a[i]);
    t = t->next;
  }
  // print
  t = head;
  while (t != nullptr) {
    cout << t->data << "->";
    t = t->next;
  }
  cout << "NULL\n";
  return 0;
}