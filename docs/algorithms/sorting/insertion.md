---
title: Insertion Sort
---

## Intuition

This works as follow,

- Consider you have a sorted array and you want to insert a element
- you will scan through the end of the sorted array and keep on shifting elements to right till
  the right position of element you want to insert is not found.

```cpp
{{ include_file('algorithms/sorting/insertion.cpp') }}
```

## Analysis

- Time complexity
    - Best: $O(n)$, if the array is sorted
    - Average: $O(n^2)$
    - Worst: $O(n^2)$
- Space complexity - $O(1)$
