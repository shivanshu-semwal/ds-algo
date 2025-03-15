#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  Node(int data) : data(data), next(nullptr), prev(nullptr) {}
  int data;
  Node* next;
  Node* prev;
};

class Queue {
private:
  Node* head;
  Node* tail;
  int capacity;

public:
  Queue() : capacity(0), head(nullptr), tail(nullptr) {}
  int front() { return head->data; }
  int back() { return tail->data; }
  int size() { return capacity; }
  bool empty() { return capacity == 0; }

  void push(int val) {
    if (this->empty()) {
      tail = new Node(val);
      head = tail;
    } else {
      tail->next = new Node(val);
      tail->next->prev = tail;
      tail = tail->next;
    }
    capacity++;
  }

  void pop() {
    if (this->empty()) return;
    Node* t = head;
    if (capacity == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
    }
    delete t;
    capacity--;
  }
};

int main() {
  Queue q;
  vector<int> a = {10, 11, 12, 13, 14, 15};
  for (auto i : a) {
    q.push(i);
  }
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}