---
title: Bubble Sort
---

## Intuition

This works as follow, you iterate through the array and check two adjacent elements
if the second one is smaller you swap them, in this way the largest number will
be at the end of array after first iteration.
In second iteration you do the same till the second last element of array, and so on.
Also keep a flag to check if any swaps are made in some iteration, if no swaps
are made you can stop as the array is already sorted.

```cpp
{{ include_file('bubble.cpp') }}
```

## Analysis

- Time complexity
    - Best: $O(n)$, if the array is sorted
    - Average: $O(n^2)$
    - Worst: $O(n^2)$
- Space complexity - $O(1)$
