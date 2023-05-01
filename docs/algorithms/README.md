# Algorithm

Algorithm is series of steps to solve a problem. In computer science an algorithm is used to solve problems.
Algorithm is a finite sequence of rigorous instructions, typically used to solve a class of specific problems or to perform a computation.

## Measuring space and time complexity

How we measure space and time complexity of algorithm depend on the computational model
we are trying to use. Generally we use turing model of computing.

## Why study analysis of algorithms?

Some algorithms are fast some are slow. Some take more space and some less.
To choose which algorithm to use we should have some analytical tools;
these are provided by analysis of algorithms

## Outline

- Algorithms - what is algorithm, space and time complexity
- [Time complexity](../analysis/time-complexity.md)
    - Big $O$ notation
    - lower bound, upper bound, tight bound
    - pseudo polynomial time, amortized time complexity
- [Arrays](../data-structures/arrays/README.md)
    - sorting and searching
- [Trees](../data-structures/trees/README.md)
    - Types: n-ary, complete tree, binary
    - [Binary Trees](../data-structures/trees/binary-tree/README.md)
        - Traversal: - inorder, preorder, postorder, level order
        - Operations: insert, delete, search
        - Binary Heap
        - Binary search tree
            - Self balancing trees - AVL trees, red black trees
        - Segment Trees
        - Trie
        - Binary Index Trees
- Graphs
    - Types: directed, undirected, weighted, cyclic, acyclic
    - Traversal: bfs, dfs
    - Operations
        - Check for cycle in graph
        - Find connected components
    - Minimum spanning tree: Kruskal Algorithm, Prim algorithms, Brovuka'a Algorithm
    - Shortest path from source to all other nodes: djkstra's, bellman ford's
    - Shortest path between all nodes to all other node: floyd warshall, Johnson's Algorithm
    - Directed Acyclic Graph (DAG): topological traversal
    - dfs-tree
    - bfs-tree
    - Connectivity
        - Path between two vertices
        - Bridges in a graph
        - Articulation Points
        - Eulerian Path
    - Union Find
- Range Queries: Segment Tree, Binary Index Trees, sqrt decomposition
- Strings:
    - Pattern Matching: KMP method, rabin karp method
    - Trie
- Hashing: simple hashing, collision on hashing
- [Algorithm Techniques](techniques/README.md)
    - Two Pointer
    - Monotonic Stack
    - Sliding Window
    - Greedy Algorithms - knapsack
    - Dynamic Programming - 0/1 knapsack algorithm, coin selection
    - Divide and Conquer - binary search, merge sort, quick sort
    - Bitwise algorithms
- P vs NP: P, NP, NP-Complete, NP-Hard

## Resources

- <https://en.wikipedia.org/wiki/Algorithm>
