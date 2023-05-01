---
title: Time complexity
---

## Time Complexity from Constraints

By looking at the constraints of a problem, we can often "guess" the solution.

### Common time complexities

Let $n$ be the main variable in the problem.

- $n \le 12$    $\rightarrow$ $O(n!)$
- $n \le 25$    $\rightarrow$ $O(2^n)$
- $n \le 100$   $\rightarrow$ $O(n^4)$
- $n \le 500$   $\rightarrow$ $O(n^3)$
- $n \le 10^4$  $\rightarrow$ $O(n^2)$
- $n \le 10^6$  $\rightarrow$ $O(n \log(n))$
- $n \le 10^8$  $\rightarrow$ $O(n)$
- $n > 10^8$  $\rightarrow$ $O(\log(n))$ or $O(1)$

Examples of each common time complexity

- $O(n!)$
    - [Factorial time]: Permutations of $1 ... n$
- $O(2^n)$
    - [Exponential time]: Exhaust all subsets of an array of size $n$
- $O(n^3)$
    - [Cubic time]: Exhaust all triangles with side length less than $n$
- $O(n^2)$
    - [Quadratic time]: Slow comparison-based sorting (eg. Bubble Sort, Insertion Sort, Selection Sort)
- $O(n log(n))$
    - [Linearithmic time]: Fast comparison-based sorting (eg. Merge Sort)
- $O(n)$
    - [Linear time]: Linear Search (Finding maximum/minimum element in a 1D array), Counting Sort
- $O(log(n))$
    - [Logarithmic time]: Binary Search, finding GCD (Greatest Common Divisor) using Euclidean Algorithm
- $O(1)$
    - [Constant time] Calculation (eg. Solving linear equations in one unknown)

### Explanations based on Codeforces problems

- **255D Mr. Bender and Square**
    - Observe that $1<=n$,$c<=109$.
    - Referring to the information above, the program's time complexity should be either
      $O(\log n)$ or $O(1)$.
    - Since no $O(1)$ solution exists, we conclude that binary search must be used.

- **580B Kefa and Company**
    - In this problem, $1 \le n \le1 05$,
    - which suggests that the time complexity can be either $O(n \log n)$ or $O(n)$.
    - It is quite obvious that sorting is required.
    - Therefore, $O(n \log n)$ is the correct solution of this problem.

- **583B Robot's Task**
    - Notice that n in very small $(1\le n \le1000)$ in this problem.
    - It means that a $O(n^2)$ solution can solve it.
    - We simply need to simulate the robot's moves.

> Note: The above method may not always work in all problems.
> Some may require algorithms that have complex time complexities, while in some
> problems like 591B Rebranding, the range of n does not match the time complexity
> of the "optimal" solution.
> ($1 \le n,m \le 200000$ suggests that the time complexity is $O(n \log n)$ or $O(n)$
> but the time complexity of the solution is actually $O(1)$.)
