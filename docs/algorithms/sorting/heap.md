---
title: Heap Sort
---

## Intuition

This works as follow,

- make a heap using heapify
- pop out the elements and put them at the end of the heap

_NOTE:_ In this code I used extra space for the heap, but I can use heapify on the array also
so that no extra space will be required.

```cpp
{{ include_file('heap.cpp') }}
```

## Analysis

- Time complexity
    - Best: $O(n \log(n))$, if the array is sorted
    - Average: $O(n \log(n))$
    - Worst: $O(n \log(n))$
- Space complexity - $O(1)$
