#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int *harr;     // heap array
    int capacity;  // maximum possible size of the heap
    int heap_size; // current no of elements in the heap

public:
    MinHeap(int);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int getMin() { return harr[0]; }      // get the min element
    void MinHeapify(int);                 // heapify form given index
    int extractMin();                     // get the min element and remove it
    void decreaseKey(int i, int new_val); // decrease key value at given index
    void deleteKey(int);                  // deleta key at index i
    void insertKey(int);                  // insert key with value i
};

MinHeap::MinHeap(int capacity) {
    heap_size = 0;
    this->capacity = capacity;
    harr = new int[capacity];
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[smallest] > harr[l]) smallest = l;
    if (r < heap_size && harr[smallest] > harr[r]) smallest = r;
    if (smallest != i) {
        int temp = harr[smallest];
        harr[smallest] = harr[i];
        harr[i] = temp;
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if (heap_size < 0) return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::decreaseKey(int i, int new_val) {
    if (new_val > harr[i]) {
        return; // new value should be smaller
    }
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        int temp = harr[i];
        harr[i] = harr[parent(i)];
        harr[parent(i)] = temp;
        i = parent(i);
    }
}

void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        cerr << "Overflow...\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i]) {
        int temp = harr[i];
        harr[i] = harr[parent(i)];
        harr[parent(i)] = temp;

        i = parent(i);
    }
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

int main() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}