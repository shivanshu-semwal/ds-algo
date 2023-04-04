---
title: Merge Sort
---

## Intuition

This works as follow,

- divide array into two haves
- sort both recursively
- merge both sorted array

```cpp
{{ include_file('merge.cpp') }}
```

## Analysis

- Time complexity
    - Best: $O(n \log(n))$, if the array is sorted
    - Average: $O(n \log(n))$
    - Worst: $O(n \log(n))$
- Space complexity - $O(n)$
