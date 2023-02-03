# Introduction

## DFS and BFS

### BFS Tree

- tree we made while traversing a graph in bfs style
- problems
    - level order traversal

### DFS Tree

DFS Tree is the data structure which is created by dfs traversal of the graph.
Read <https://codeforces.com/blog/entry/68138> for more detailed description.

## Graph Cycle

How to detect cycle in graphs (directed or undirected graph).
Methods which exist are using colors, negative cycle using
floyd warshalls or bellman ford.

### Problems

- Assign directions to edges so that the graph remain acyclic
- Clone a directed acyclic graph
- Disjoint set

## Topological sort

> possible only for directed acyclic graphs

- find all possible topological graphs
- methods
    - dfs
    - khan's algo
- maximum edges that can be added to dag so it still remains dag
- longest path between pair of vertices
- longest path in dag

## Minimum Spanning Trees

MST is tree which includes all the vertices of the graph and the weight is minimum for them.
Don't make sense for unweighted graphs.

- methods
    - prim's algo
    - kruskals algo
    - boruvka's algo
- total no of spanning tree of a graph
- minimum product spanning tree

## Backtracking

- rat in the maze
- n-queens problem
- m-colouring problem
- hamiltoninan cycle
- permutaion of numbers such that the sum of two consequtive numbers is a prefect square

## Shortest Paths

Find shortest path from a given vertex to all the remaining vertex.

- methods - single pair shortest path
    - dijkstra's algorithm
    - bellman ford's algorithm
- methods - all pair shortest path
    - floyd warshall algorithm
    - johnson's algorithm
- dag shortest path
- in unweighted graph

## Connectivity

Find if there is path between two vertices.

- articulation points or cut vertices
- biconnected components
- bridges
- eulerian path and circoit
    - felury algorithm
- strongly connected components
- transtive closure of graph

- count all possible walks form a source to destination
