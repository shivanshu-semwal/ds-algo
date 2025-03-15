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
        - Kosaraju's algorithm, Tarjans Algorithm
    - Minimum spanning tree
        - Kruskal Algorithm, Prim algorithms, Brovuka'a Algorithm
    - Shortest path from source to all other nodes
        - Djkstra's Algorithm, Bellman ford's
    - Shortest path between all nodes to all other node
        - Floyd Warshall, Johnson's Algorithm
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


## Shortest Path Problem

- Find the shortest path from node A to node B in the given graph.
- Find shortest path from node A to all other nodes

- Dijkstra Algorithm
- Bellman's Ford Algorithm

## Shortest Path Problem for all node

- Determine the shortest paths from node A to all other nodes in the graph.
- Find shortest path from all node to all other nodes

- Floyd Warshall
- Johnson's Algorithm

## Hamiltonian Cycle

- Determine if a path exists that visists each city once.

## Traveling Salesman Problem (TSP)

- What is the shortest path that visits all nodes in the graph exactly once and returns to the starting node?
- Determine the shotest path of a hamiltoninan cycle.

## Minimum Spanning Tree

- Find the minimum spanning tree of the given graph.
- Kruskal Algorithm
- Prim algorithms
- Brovuka'a Algorithm

## Connectivity Testing

- Is the graph connected, or are there disconnected components?

- Kosaraju's algorithm
- Tarjans Algorithm

## Cycle Detection

- Does the graph contain any cycles?

## Graph Coloring

- What is the minimum number of colors required to color the nodes of the graph such that no two adjacent nodes have the same color?

## Bipartite Graph Detection

- Is the given graph bipartite?

## Eulerian Path/Circuit

- Does the graph contain an Eulerian path or circuit?

## Planarity Testing

- Is the graph planar, meaning it can be drawn on a plane without any edge crossings?

## Graph Diameter

- What is the diameter of the graph, i.e., the longest shortest path between any two nodes?

## Centrality Measures

- Which node is the most central in the graph according to the betweenness centrality?
