#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Node {
public:
  Node(int data) : data(data), next(nullptr), prev(nullptr) {}
  int data;
  Node* next;
  Node* prev;
};

class Dequeue {
private:
  Node* head;
  Node* tail;
  int capacity;

public:
  Dequeue() : capacity(0), head(nullptr), tail(nullptr) {}
  int front() { return head->data; }
  int back() { return tail->data; }
  int size() { return capacity; }
  bool empty() { return capacity == 0; }

  void push_back(int val) {
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

  void push_front(int val) {
    if (this->empty()) {
      head = new Node(0);
      tail = head;
    } else {
      head->prev = new Node(val);
      head->prev->next = head;
      head = head->prev;
    }
    capacity++;
  }

  void pop_back() {
    if (this->empty()) return;
    Node* t = tail;
    if (capacity == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      tail = tail->prev;
      tail->next = nullptr;
    }
    delete t;
    capacity--;
  }

  void pop_front() {
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
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> aa = {10, 11, 12, 13, 14, 15};

  Dequeue d;

  for (int i = 0; i < a.size(); i++) {
    d.push_back(a[i]);
  }
  for (int i = 0; i < aa.size(); i++) {
    d.push_front(aa[i]);
  }
  while (!d.empty()) {
    cout << d.front() << " ";
    d.pop_front();
  }
  return 0;
}