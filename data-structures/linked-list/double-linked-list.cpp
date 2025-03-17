#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node* prev;
  Node(int data, Node* next, Node* prev) : data(data), next(next), prev(prev) {}
  Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

int main() {
  vector<int> a = {1, 2, 3, 4, 5};
  Node* head = new Node(a[0]);

  Node* t = head;
  Node* prev = nullptr;
  for (int i = 1; i < a.size(); i++) {
    t->next = new Node(a[i]);
    t->prev = prev;
    prev = t;
    t = t->next;
  }
  t->prev = prev;

  // print
  t = head;
  while (t->next != nullptr) {
    cout << t->data << "->";
    t = t->next;
  }
  while (t->prev != nullptr) {
    cout << t->data << "->";
    t = t->prev;
  }
  cout << "NULL";
  return 0;
}