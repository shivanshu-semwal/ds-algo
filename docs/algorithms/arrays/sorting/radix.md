---
title: Radix Sort
---

## Intuition

This works as follow,

- you count sort all no. based on their last digit
- then count sort all no. based on second last digit, and so on...
- till we sort by the no. of digits in the largest no.

```cpp
{{ include_file('radix.cpp') }}
```

## Analysis

- $d$ - the number of digits in number
- $b$ - the base of the numbers to be sorted
- Time complexity
    - Best: $O(d (n+b))$, if the array is sorted
    - Average: $O(d (n+b) )$
    - Worst: $O(d (n+b))$
- Space complexity - $O(n+b)$
