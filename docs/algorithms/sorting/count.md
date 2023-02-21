---
title: Count Sort
---

## Intuition

This works as follow,

- you are given array `arr` with numbers within range $[1, n]$
- first you find the relative frequency of all numbers form $[1, n]$ in `arr`
- then you calculate the cumulative frequency
- now position of a particular element $x$ in the sorted array will be
  the cumulative frequency of the $x-1$ because that many elements
  will appear before it in the array.

```cpp
{{ include_file('count.cpp') }}
```

## Analysis

- $k$ - the range of numbers
- $n$ - the size of array
- Time complexity
    - Best: $O(n+k)$, if the array is sorted
    - Average: $O(n+k)$
    - Worst: $O(n+k)$
- Space complexity - $O(k+n)$
