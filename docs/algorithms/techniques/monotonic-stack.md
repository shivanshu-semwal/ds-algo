# Monotonic Stack

- when to use stack
- when( you have $O(n^2)$ solution and the inner loop is dependent on j
    - then you can have better solution in $O(n)$

```c
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        // n^2 code complexity
        // actually - n(n+1)/2 time complexity
        // so we can use stack here to make it better
    }
}
```

## Questions

- nearest greater to left
- nearest greater to right
- nearest smaller to right
- nearest smaller to left
- <https://leetcode.com/problems/next-greater-element-i/>
- <https://leetcode.com/problems/online-stock-span/>