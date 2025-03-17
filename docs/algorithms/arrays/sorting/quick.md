---
title: Quick Sort
---

## Intuition

This works as follow,

- choosing a pivot
- move all elements smaller to left of pivot (larger to right)
- now recursively sort the two halves

```cpp
{{ include_file('quick.cpp') }}
```

## Analysis

- Time complexity
    - Best: $O(n \log(n))$, if the array is sorted
    - Average: $O(n \log(n))$
    - Worst: $O(n^2)$
- Space complexity - $O(1)$
