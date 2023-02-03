---
title: P vs NP
---

## P - polynomial time

- problems which can be solved in polynomial time
- they can also be verified in polynomial time
- like sorting, searching in array

## NP - non deterministic polynomial time

- problems which can be verified in polynomial time
- till now
    - they cannot be solved using polynomial time
    - in future they can be solve if $P=NP$
- like verifying if a jigsaw puzzle is valid or if a sudoku puzzle is valid

## P vs NP

- this problem states is it possible if a problem in verifiable in polynomial time
  is it also solvable in polynomial time?

## NP-Complete

- $C$ problem is NP-complete if
    - $C$ is NP
    - every problem in NP is reducible $C$ in polynomial time,
      if the first condition is not satisfied but the the second one is
      then it is NP-Hard Problem.

## NP-Hardness

- problem $H$ is NP-hard when
    - every problem $L$ in NP can ve reduced in polynomial time to $H$
- problem at least as hard as the problem in NP
- e.g. subset sum
- finding a polynomial time solution to any NP-hard problem would give
  polynomial time to solve all problems in NP.

## tldr

- p - solves polynomial time and verifies them in polynomial time
    - e.g. linear search
- np - verifies problem in polynomial time
    - eg
- np-complete
    - is np
    - and every problem in np can be converted to this one in polynomial time
    - e.g. - subset sum when all no are positive
- np-hard
    - is not np - cannot be verified in polynomial time
    - every problem in np can be mapped to this one in some way
    - e.g. - subset sum problem

## what if P=NP

- then P=NP=NP-complete
- then every problem that is verifiable in polynomial time will also be solvable
  in polynomial time.

## what if P!=NP

- this is more likely what will happen
- it this happen
    - NP problems will not be solvable in polynomial time

![pvsnp](img/p-vs-np.svg)

## NP complete problems list

Some NP complete problems and there descriptions.

### SAT - boolean satisfiability problem

- **Problem**
    - if there exists an interpretation that satisfies a given boolean formula
    - in simple terms given a boolean expression
        - what are the possible values of variables in that expression for which the answer is true

### Hamiltonian Path Cycle

- **Problem**
    - determining whether a hamintonian path or a hamintonian cycle exists or not

- hamiltonian path
    - visit each vertex once
    - if you end up at the starting vertex it becomes cycle

### Knapsack Problem

- given a knapsack and its capacity
- and some items are given with there weight and value

**0/1 knapsack**

- you have to pick zero or one item of each type
- and maximize the total value

**bounded knapsack**

- you have to pick zero or more items of each type
- and maximize the total value

### Traveling Salesman Problem

- given list of cities and the distances between each pairs of cities, what is the
  shortest possible route that visits each city exactly once and return the city of origin.

### Subset sum problem

- given array and some number N
- find the subset whose sum is closest to N
