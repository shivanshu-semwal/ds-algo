#include <stdio.h>
#include <stdlib.h>

/*
    help func fot heapify
*/
void heapify_help(int* a, int n, int i) {
  int largest = i; // assume current one as largest
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && a[l] > a[largest]) largest = l;
  if (r < n && a[r] > a[largest]) largest = r;

  if (largest != i) {
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    heapify_help(a, n, largest);
  }
}

/*
    make heap
*/
void heapify(int* a, int n) {
  // starting from end
  // or
  // since all the leaf node will remain on there pos at start
  // start form the parent of last node i.e (n/2) - 1
  for (int i = (n / 2) - 1; i >= 0; i--) {
    // check the subtree
    heapify_help(a, n, i);
  }
}

/*
    structure for heap
*/
typedef struct heap {
  int* arr;     // array to store the contents of heap
  int capacity; // capacity of the heap
  int size;     // current size of the heap
} heap;

/*
    make heap of capacity n
    start size is 0
*/
heap* makeHeap(int n) {
  heap* new = (heap*)malloc(sizeof(heap));
  int* arr = (int*)malloc(sizeof(int));
  new->arr = arr;
  new->capacity = n;
  new->size = 0;
  return new;
}

/*
    make heap form another array
    of size n
    capacity will be set to n
*/
heap* makeHeap2(int* a, int n) {
  heap* new = (heap*)malloc(sizeof(heap));
  heapify(a, n);
  new->arr = a;
  new->size = n;
  new->capacity = n;
}

/*
    get the max form heap
*/
int pop(heap* h) {
  if (h->size <= 0) return 0;     // heap is empty
  int temp = h->arr[0];           // value to return;
  int last = h->arr[h->size - 1]; // last element

  h->arr[0] = last;
  heapify_help(h->arr, h->size - 1, 0); // heapify from root

  h->arr[h->size - 1] = temp; // store the removed at the end if you want
  (h->size)--;                // decrease the size
  return temp;
}

/*
    push a value to the heap
    return 0 if heap is full
*/
int push(heap* h, int val) {
  if (h->size == h->capacity) return 0; // heap is full
  h->size++;
  h->arr[h->size - 1] = val;

  // adjust the node
  int i = h->size - 1;
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (h->arr[parent] < h->arr[i]) {
      // swap them
      int temp = h->arr[i];
      h->arr[i] = h->arr[parent];
      h->arr[parent] = temp;
      i = parent;
    } else {
      break;
    }
  }
  return 1; // successful insertion
}

/*
    print heap
*/
void print_heap(heap* h) {
  printf("arr: ");
  for (int i = 0; i < h->size; i++) {
    printf("%d, ", h->arr[i]);
  }
  printf("\n");
  printf("rest: ");
  for (int i = h->size; i < h->capacity; i++) {
    printf("%d, ", h->arr[i]);
  }
  printf("\n");
}

void heap_sort(int* a, int n) {
  heap* h = makeHeap2(a, n);
  while (pop(h)) {
  };
  free(h);
}

int main() {
  int a[] = {1, 2, 54, 23, 21, 32, 31};
  heap* h = makeHeap2(a, 7);

  printf("----------------------\n");
  print_heap(h);
  printf("----------------------\n");
  printf("doing heap sort:\n");

  int i;
  while (i = pop(h)) {
    printf("%d \n", i);
    print_heap(h);
  }

  push(h, 1);
  push(h, 2);
  push(h, 54);
  push(h, 23);
  push(h, 21);
  push(h, 32);
  push(h, 31);
  print_heap(h);

  int b[] = {1, 232, 323, 21, 23, 21};
  int n = 6;
  heap_sort(b, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
  return 0;
}