# Divide and Conquer

- first you divide in subproblem
- then you merge them

OR

- you do some computation
- then you crete two or more same subproblem to solve

## Time Complexity

- you have to make a recurrence relation for
  time complexity, and then solve it using Masters Theorem.

## Merge Sort

- split array into two
- sort them recursively
- merge them

## quick sort

- find pivot, and separate elements
- sort the other parts recursively

## Master's Theorem

- used for recurrence relations
- for example divide and conquer

$$
T(n) = a \times T \left( \frac{n}{b} \right)  + f(n)
$$

here

- $n$ is the size of sample input

also,

- $n/b$  in how many parts we divided the problems
- and $f(n)$ is the complexity of merging those parts
- $a$ no of subproblem

$$
T(n) = b^{c_{crit}} \times T\left(\frac{n}{b}\right) + f(n)
$$

$$
T(n) = b^{c_{crit}} \times T\left(\frac{n}{b}\right) + O(n^c)
$$

- $c < c_{crit}$
    - $T(n) = \Theta(n^{c_{crit}})$
- $c > c_{crit}$
    - $T(n) = \Theta(n^{c})$
- $c = c_{crit}$
    - $T(n) = \Theta(n^c \log n)$
        - another thing is, if $f(n) = \Theta(n^{c_{crit}} \log^k n)$
            - $k > -1$ then $T(n) = \Theta(n^c \log^{k+1} n)$
            - $k = -1$ then $T(n) = \Theta(n^c \log \log n)$
            - $k < -1$ then $T(n) = \Theta(n^c)$
