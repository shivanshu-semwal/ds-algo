# Binary Heap

Binary heap is a binary tree in which each parent is greater than it's child node or
each parent is smaller than it's parent.
It is often used to implement a priority queue.

## Implementation

- to implement a binary heap we can use either representation
- to insert a element, we inset it at the end of the tree and bubble it's way up
- to remove a top element we replace last element with the top one and bubble it's way down

## Sample Implementation

```c
{{ include_file('heap.c') }}
```