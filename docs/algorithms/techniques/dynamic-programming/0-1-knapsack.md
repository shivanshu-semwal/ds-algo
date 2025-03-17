# 0/1 knapsack type problem

## Description

- we are given
    - two arrays - one for the weight of item and one for the price
    - a value which is equal to the capacity of knapsack
- for each item we have a choice
    - we should take the item
    - we should not take the item
    - you cannot take half of the item

## Recursive Solution

```cpp
{{ include_file('0-1-knapsack/recurse.cpp') }}
```

## Memoization solution

```cpp
{{ include_file('0-1-knapsack/memoize.cpp') }}
```

## top down approach

```cpp
{{ include_file('0-1-knapsack/top-down.cpp') }}
```

## practice que

- 0/1 knapsack
    - <https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1>
- subset sum problem
    - <https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1>
- equal sum partition
    - <https://leetcode.com/problems/partition-equal-subset-sum/>
- count no of subset with given sum
    - <https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/>
- minimum subset difference problem
    - <https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/>
- count the number of subset with given difference
    - <https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/>
- target sum
    - <https://leetcode.com/problems/target-sum/>
- <https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/>
