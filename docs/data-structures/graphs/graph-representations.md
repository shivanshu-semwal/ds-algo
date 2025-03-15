# Graph Representations

## Edge List

- this will be that usual graph representation that you will be provided
  and will have to convert this to another representation
- it is a list which contains item of form, (u, v, weight)
  which represents that u vertex is connected to v vertex with given weight

## Adjacency Matrix

- given $n$ vertices
- you have to create a $n * n$ matrix
- the ith row and jth col will represent if the ith vertex and jth vertex are
  connected or not, and if graph is weighted it can be filled with that value
- good if you have a dense graph, but takes too much space for a sparse graph

## Adjacency List

- in this you create a array of list where, the list at ith index
  will contains all the vertices ith vertex is connected to
- good if you have a sparse graph
