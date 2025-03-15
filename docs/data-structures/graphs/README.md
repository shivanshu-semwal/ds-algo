# Graphs

- Types of Graphs
- Graph Traversal
    - Breadth first search BFS, BFS Tree
    - Depth first search DFS, DFS Tree
- Union Find
- Directed Acyclic Graph (DAG)
    - Topological traversal
    - Check for cycle in graph
- On weighted graph
    - Find connected components
            - Kosaraju's algorithm - <https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm>
            - Tarjans Algorithm - <https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm>
    - Minimum spanning tree
        - Kruskal Algorithm
        - Prim algorithms
        - Brovuka'a Algorithm
    - Shortest path from source to all other nodes
        - Djkstra's Algorithm
        - Bellman ford's
    - Shortest path between all nodes to all other node
        - Floyd Warshall  - <https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm>
        - Johnson's Algorithm - <https://en.wikipedia.org/wiki/Johnson%27s_algorithm>
    - Detect negative cycles
- Connectivity
    - Path between two vertices
    - Bridges in a graph
    - Articulation Points
- Traveling Salesman Problem (TSP)
- Network Flow (max flow)
    - Ford Fulkerson

## Checking for Graph Cycle

How to detect cycle in graphs (directed or undirected graph).
Methods which exist are using colors, negative cycle using
floyd warshalls or bellman ford.

### Problems

- Assign directions to edges so that the graph remain acyclic
- Clone a directed acyclic graph
- Disjoint set

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
- m-coloring problem
- hamiltonian cycle
- permutation of numbers such that the sum of two consecutive numbers is a prefect square

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
