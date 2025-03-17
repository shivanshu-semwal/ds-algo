# Unbounded knapsack type problem

## Description

- we are given
    - two arrays - one for the weight of item and one for the price
    - a value which is equal to the capacity of knapsack
- for each item we have a choice
    - we should take the item **multiple times**
    - we should not take the item
    - you cannot take half of the item

## recursive sol

```cpp
{{ include_file('unbounded-knapsack/recurse.cpp') }}
```

## memoization solution

```cpp
{{ include_file('unbounded-knapsack/memoize.cpp') }}
```

## top down approach

```cpp
{{ include_file('unbounded-knapsack/top-down.cpp') }}
```

## practice que

- unbounded knapsack
    - <https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/>
- rod cutting problem
    - <https://practice.geeksforgeeks.org/problems/rod-cutting0840/1>
- coin change problem - maximum no. of ways
    - <https://leetcode.com/problems/coin-change/>
- coin change problem - minimum no of coins
