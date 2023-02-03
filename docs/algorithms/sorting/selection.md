---
title: Selection Sort
---

## Intuition

This works as follow, you pick the smallest element and put it in first,
and then you pick the smallest form the remaining elements and put it in the second, and so on.

```cpp
{{ include_file('algorithms/sorting/selection.cpp') }}
```

## Analysis

- Time complexity
    - Best: $O(n)$, if the array is sorted
    - Average: $O(n^2)$
    - Worst: $O(n^2)$
- Space complexity - $O(1)$
